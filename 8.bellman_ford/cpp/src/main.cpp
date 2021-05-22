#include <iostream>
#include <vector>
#include <climits>

const int UNKNOWN = INT_MAX;

class Edge {
public:
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

int main(int argc, char* argv[]) {
    int V, E;

    FILE* file = std::fopen(argv[1], "r");
    std::fscanf(file, "%d %d", &V, &E);

    std::vector<Edge*> edges;
    std::vector<int> dist;
    for(int i=0;i<V;i++) {
        if(i==0) dist.push_back(0);
        else dist.push_back(UNKNOWN);
    }

    for(int i=0; i<E; i++) {
        int from, to, weight;
        std::fscanf(file, "%d %d %d", &from, &to, &weight);

        edges.push_back(new Edge(from, to, weight));
    }

    // bellman-ford
    for(int i=0;i<V-1;i++) {
        bool changed = false;
        for(Edge* edge: edges) {
            if(dist[edge->from] != UNKNOWN && dist[edge->to] > dist[edge->from] + edge->weight) {
                dist[edge->to] = dist[edge->from] + edge->weight;
                changed = true;
            }
        }

        if(!changed) break;
    }

    // check negative cycle
    bool has_neg_cycle = false;
    for(Edge* edge: edges) {
        if(dist[edge->to] > dist[edge->from] + edge->weight) {
            has_neg_cycle = true;
            break;
        }
    }

    if(has_neg_cycle) std::printf("Has negative cycle !!\n");
    else {
        int index = 0;
        for(int d: dist) {
            printf("%d: %d\n", index, d);
            index++;
        }
    }

    return 0;
}
