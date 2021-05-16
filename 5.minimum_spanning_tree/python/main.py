import argparse
from queue import PriorityQueue

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

class Vertex:
    def __init__(self, index):
        self.index = index

        self.group = index
        self.child = []

class Edge:
    def __init__(self, v1, v2, weight):
        self.v1 = v1
        self.v2 = v2
        self.weight = weight
    
    def __lt__(self, other):
        return self.weight < other.weight

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        N = int(f.readline())

        vertices = [Vertex(i) for i in range(N+1)]
        edges = PriorityQueue()

        for line in f:
            v1, v2, weight = tuple(map(lambda x: int(x), line.split(" ")))
            
            edges.put(Edge(vertices[v1], vertices[v2], weight))

    while not edges.empty():
        edge = edges.get()


