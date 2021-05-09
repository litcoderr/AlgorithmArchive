#include <iostream>
#include "node.hpp"

int main(int argc, char* argv[]) {
    FILE* input_file = std::fopen(argv[1], "r");

    int N; // number of nodes
    fscanf(input_file, "%d", &N);

    // dynamically allocate nodes
    Node** nodes = new Node*[N];
    for(int i=0;i<N;i++) {
        nodes[i] = new Node(i);
    }

    // initialize adjacent nodes
    int n_a, n_b;
    while(fscanf(input_file, "%d", &n_a)!=EOF) {
        fscanf(input_file, "%d", &n_b);
        nodes[n_a]->adj.push_back(nodes[n_b]);
        nodes[n_b]->adj.push_back(nodes[n_a]);
    }

    // bfs
    std::vector<int> bfs_trav_order;
    search::bfs(N, nodes, 0, bfs_trav_order);
    printf("bfs order: ");
    for(int idx: bfs_trav_order) {
        printf("%d ", idx);
    }
    printf("\n");

    // dfs
    std::vector<int> dfs_trav_order;
    search::dfs(N, nodes, 0, dfs_trav_order);
    printf("dfs order: ");
    for(int idx: dfs_trav_order) {
        printf("%d ", idx);
    }
    printf("\n");

    // free nodes
    for(int i=0;i<N;i++) {
        delete nodes[i];
    }
    delete[] nodes;

    return 0;
}