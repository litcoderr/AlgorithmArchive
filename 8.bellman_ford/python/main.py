import sys
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

UNKNOWN = sys.maxsize

class Edge:
    def __init__(self, from_: int, to_: int, weight: int):
        self.from_: int = from_
        self.to_: int = to_
        self.weight: int = weight

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        V, E = tuple(map(lambda x: int(x), f.readline().split(" ")))
        
        nodes = [0 if i == 0 else UNKNOWN for i in range(V)]
        edges = []

        for line in f:
            from_, to_, weight = tuple(map(lambda x: int(x), line.split(" ")))
            edges.append(Edge(from_=from_, to_=to_, weight=weight))
    
    # bellman-ford
    for _ in range(V-1):
        changed = False
        for edge in edges:
            if nodes[edge.from_] != UNKNOWN and nodes[edge.to_] > nodes[edge.from_] + edge.weight:
                nodes[edge.to_] = nodes[edge.from_] + edge.weight
                changed = True
        
        if not changed:
            break
    
    # check for negative weighted cycle
    has_negative_cycle = False
    for edge in edges:
        if nodes[edge.to_] > nodes[edge.from_] + edge.weight:
            has_negative_cycle = True
            break
    
    if has_negative_cycle:
        print("has negative cycle")
    else:
        for idx, dist in enumerate(nodes):
            print("{} : {}".format(idx, dist))
