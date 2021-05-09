#include "node.hpp"
#include <queue>

Node::Node(int index) {
    this->index = index;
}

void search::bfs(int N, Node** nodes, int start, std::vector<int>& order) {
    bool visited[N];
    for(int i=0;i<N;i++) {
        visited[i] = false;
    }

    std::queue<Node*> que;
    que.push(nodes[start]);
    visited[start] = true;

    while(!que.empty()) {
        Node* cur_node = que.front();
        que.pop();
        order.push_back(cur_node->index);

        for(Node* adj: cur_node->adj) {
            if(!visited[adj->index]) {
                que.push(adj);
                visited[adj->index] = true;
            }
        }
    }
}

void search::dfs(int N, Node** nodes, int start, std::vector<int>& order) {
    bool visited[N];
    for(int i=0;i<N;i++) {
        visited[i] = false;
    }

    search::dfs_(N, nodes, start, order, visited);
}

void search::dfs_(int N, Node** nodes, int current, std::vector<int>& order, bool* visited) {
    visited[current] = true;
    order.push_back(current);

    for(Node* adj: nodes[current]->adj) {
        if(!visited[adj->index]) {
            search::dfs_(N, nodes, adj->index, order, visited);
        }
    }
}

