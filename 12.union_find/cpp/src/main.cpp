#include <iostream>
#include <vector>

class Node;

void node_union(Node* n1, Node* n2);
Node* node_find(Node* n);

void union_(Node* to, Node* from);

void visualize_set(Node* n);

class Node {
public:
    int index;
    Node* parent;
    std::vector<Node*> child;

    Node(int index) {
        this->index = index;
        this->parent = this;
    }
};

int main() {
    int N = 10;

    Node** nodes = new Node*[N];
    for(int i=0;i<N;i++) {
        nodes[i] = new Node(i);
    }

    // union first set
    node_union(nodes[0], nodes[1]);
    node_union(nodes[2], nodes[1]);
    node_union(nodes[2], nodes[3]);
    node_union(nodes[0], nodes[4]);
    
    visualize_set(nodes[0]);

    //union second set
    node_union(nodes[5], nodes[6]);
    node_union(nodes[6], nodes[7]);
    node_union(nodes[6], nodes[8]);
    node_union(nodes[5], nodes[9]);

    visualize_set(nodes[5]);

    // union first and second set to one
    node_union(nodes[2], nodes[8]);

    visualize_set(nodes[0]);

    return 0;
}

void node_union(Node* n1, Node* n2) {
    Node* p1 = n1->parent;
    Node* p2 = n2->parent;

    // union set that has less child nodes
    if(p1->child.size() < p2->child.size()) union_(p2, p1);
    else union_(p1, p2);
}

Node* node_find(Node* n) {
    return n->parent;
}

void union_(Node* to, Node* from) {
    // append from's child to "to"
    for(Node* child: from->child) {
        child->parent = to;
        to->child.push_back(child);
    }

    // append from node to "to"
    from->child.clear();
    from->parent = to;
    to->child.push_back(from);
}

void visualize_set(Node* n) {
    Node* parent = n->parent;
    printf("%d\n", parent->index);
    if(parent->child.size()>0) {
        for(Node* child: parent->child) {
            printf("%d | ", child->index);
        }
        printf("\n");
    }
}