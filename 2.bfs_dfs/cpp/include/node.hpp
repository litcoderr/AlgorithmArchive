#ifndef NODE_H
#define NODE_H

#include <vector>


class Node {
public:
    int index;
    std::vector<Node*> adj;

    Node(int index);
};

namespace search {
    void bfs(int N, Node** nodes, int start, std::vector<int>& order);
    void dfs(int N, Node** nodes, int start, std::vector<int>& order);
    void dfs_(int N, Node** nodes, int current, std::vector<int>& order, bool* visited);
}

#endif