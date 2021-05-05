#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
public:
    int idx;
    int in_dim;
    int temp;
    std::vector<Node*> to; 

    Node();
};

#endif