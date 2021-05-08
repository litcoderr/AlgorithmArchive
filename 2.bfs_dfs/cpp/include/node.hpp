#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
public:
    int index;
    std::vector<Node*> adj;

    Node(int index);
};

#endif