#include <iostream>
#include <vector>
#include <queue>

typedef struct Edege {
    int v1;
    int v2;
    int weight;
} Edge;

class Vertex {
public:
    Vertex* parent;
    std::vector<Vertex*> child;

    Vertex() {
        parent = this;
    }
};

bool isCycle(Vertex* v1, Vertex* v2) {
    if(v1->parent==v2->parent) return true;
    else false;
}

bool merge_(Vertex* v_parent, Vertex* v_child) {
    if(!isCycle(v_parent, v_child)) { // merge only if v1 and v2 is not a cycle
        for(Vertex* v: v_child->child) {
            merge_(v_parent, v);
        }

        v_child->parent = v_parent;
        v_child->child.clear();
        v_parent->child.push_back(v_child);

        return true;
    }else return false;
}

bool merge(Edge& edge, std::vector<Vertex*>& vertices) {
    Vertex* v1 = vertices[edge.v1];
    Vertex* v2 = vertices[edge.v2];

    if(v1->child.size() > v2->child.size()) {
        return merge_(v1, v2);
    }else {
        return merge_(v2, v1);
    }
}

class EdgeCompare {
public:
    bool operator() (Edge& e1, Edge& e2) {
        return e1.weight > e2.weight;
    }
};

int main(int argc, char* argv[]) {
    int N;

    FILE* file = fopen(argv[1], "r"); 
    fscanf(file, "%d", &N);

    // read edges
    std::vector<Edge> edges;
    std::vector<Vertex*> vertices;

    int v1, v2, weight;
    while(fscanf(file, "%d %d %d", &v1, &v2, &weight) != EOF) {
        Edge edge = {v1, v2, weight};
        edges.push_back(edge);
    }
    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> que(edges.begin(), edges.end());

    for(int i=0; i<=N; i++) {
        Vertex* v = new Vertex();
        vertices.push_back(v);
    }

    // compute kruskal's algorithm
    std::vector<Edge> result;
    while(!que.empty()) {
        Edge e = que.top();
        que.pop();

        bool did_merge = merge(e, vertices);
        if (did_merge) result.push_back(e);
    }

    for(Edge e: result) {
        printf("%d %d %d\n", e.v1, e.v2, e.weight);
    }

    return 0;
}
