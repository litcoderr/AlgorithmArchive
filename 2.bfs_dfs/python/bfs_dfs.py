from typing import List

class Node:
    def __init__(self, idx):
        self.idx: int = idx
        self.adj: List[Node] = []

def bfs(start, nodes, bfs_order):
    que = []
    visited = [False for _ in range(len(nodes))]

    que.append(nodes[start])
    visited[start] = True

    while len(que)>0:
        cur_node = que[0]
        bfs_order.append(cur_node.idx)
        que.pop(0)

        for adj_node in cur_node.adj:
            if not visited[adj_node.idx]:
                que.append(adj_node)
                visited[adj_node.idx] = True

def dfs(start, nodes, dfs_order):
    visited = [False for _ in range(len(nodes))]

    dfs_(start, nodes, dfs_order, visited)

def dfs_(cur_idx, nodes, dfs_order, visited):
    visited[cur_idx] = True
    dfs_order.append(cur_idx)

    for adj_node in nodes[cur_idx].adj:
        if not visited[adj_node.idx]:
            dfs_(adj_node.idx, nodes, dfs_order, visited)