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

    return 0;
}