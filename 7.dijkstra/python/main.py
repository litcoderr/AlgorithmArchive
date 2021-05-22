import argparse
import heapq
from typing import List

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

MAX_NUM = 987654321

class Node:
    def __init__(self, index: int, initial_dist: int):
        self.index: int = index
        self.dist: int = initial_dist
        self.visited: bool = False

        self.edges: List[Edge] = []
    
    def __lt__(self, n2: 'Node'):
        return self.dist < n2.dist

class Edge:
    def __init__(self, adj: Node, weight: int):
        self.adj: Node = adj
        self.weight: int = weight

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        V, E = tuple(map(lambda x: int(x), f.readline().split(" ")))

        nodes = [Node(index=index, initial_dist=0) if index == 0 else 
                 Node(index=index, initial_dist=MAX_NUM) for index in range(V)]
        
        for line in f:
            n1, n2, weight = tuple(map(lambda x: int(x), line.split(" ")))
            nodes[n1].edges.append(Edge(nodes[n2], weight))    
            nodes[n2].edges.append(Edge(nodes[n1], weight))    

    que = [node for node in nodes]
    heapq.heapify(que)

    while len(que) > 0:
        node = heapq.heappop(que)
        
        for edge in node.edges:
            temp_dist = node.dist + edge.weight
            if edge.adj.dist > temp_dist:
                edge.adj.dist = temp_dist
                heapq._siftup(que, edge.adj.index)
        
    for node in nodes:
        print("index: {} dist: {}".format(node.index, node.dist))