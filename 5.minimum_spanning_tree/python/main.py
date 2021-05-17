import argparse
from queue import PriorityQueue

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

class Vertex:
    def __init__(self, index):
        self.index = index

        self.group = self
        self.child = []

class Edge:
    def __init__(self, v1, v2, weight):
        self.v1 = v1
        self.v2 = v2
        self.weight = weight
    
    def __lt__(self, other):
        return self.weight < other.weight

def merge(v1: Vertex, v2: Vertex):
    if v1.group != v2.group:
        if len(v1.group.child) > len(v2.group.child):
            merge_(v1.group, v2)
        else:
            merge_(v2.group, v1)
        return True
    else:
        return False

def merge_(parent: Vertex, v2: Vertex):
    """
    merge v2 and v2's sub group to parent
    """
    for child in v2.child:
        merge_(parent, child)

    v2.group = parent
    v2.child = []

    parent.child.append(v2)

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        N = int(f.readline())

        vertices = [Vertex(i) for i in range(N+1)]
        edges = PriorityQueue()

        for line in f:
            v1, v2, weight = tuple(map(lambda x: int(x), line.split(" ")))
            
            edges.put(Edge(vertices[v1], vertices[v2], weight))

    result = []
    while not edges.empty():
        edge = edges.get()
        success = merge(edge.v1, edge.v2)
        
        if success:
            result.append(edge)

    for edge in result:
        print("v1: {} v2: {} weight: {}".format(edge.v1.index, edge.v2.index, edge.weight))