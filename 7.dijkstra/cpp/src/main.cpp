#include <iostream>
#include <vector>
#include <queue>

#define BIG_NUM (987654321)

typedef struct Edge Edge;

class Node {
public:
    int index;
    int dist;
    bool visited;
    std::vector<Edge*> edge;

    Node(int index, int dist) {
        this->index = index;
        this->dist = dist;
        this->visited = false;
    }
};

struct Edge {
    Node* adj;
    int weight;

    Edge(Node* adj, int weight) {
        this->adj = adj;
        this->weight = weight;
    }
};

class NodeCompare {
public:
    bool operator() (Node* n1, Node* n2) {
        return n1->dist > n2->dist;
    }
};

int main(int argc, char* argv[]) {
    int V, E;

    FILE* file = std::fopen(argv[1], "r");
    std::fscanf(file, "%d %d", &V, &E);

    std::vector<Node*> nodes;
    for(int i=0;i<V;i++) {
        Node* node;
        if(i==0) node = new Node(i, 0);
        else node = new Node(i, BIG_NUM);
        nodes.push_back(node);
    }

    int n1, n2, weight;
    while(std::fscanf(file, "%d %d %d", &n1, &n2, &weight) != EOF) {
        nodes[n1]->edge.push_back(new Edge(nodes[n2], weight));
        nodes[n2]->edge.push_back(new Edge(nodes[n1], weight));
    }

    std::priority_queue<Node*, std::vector<Node*>, NodeCompare> que(nodes.begin(), nodes.end());

    while(!que.empty()) {
        Node* node = que.top();
        que.pop();

        for(Edge* e: node->edge) {
            int temp_dist = node->dist + e->weight;
            if(temp_dist < e->adj->dist) {
                e->adj->dist = temp_dist;
            }
        }
    }

    for(Node* node: nodes) {
        std::printf("index: %d dist: %d\n", node->index, node->dist);
    }

    return 0;
}
