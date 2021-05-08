import argparse
from typing import List

parser = argparse.ArgumentParser()
parser.add_argument("--input_file", type=str)
args = parser.parse_args()

class Node:
    def __init__(self, idx):
        self.idx = idx
        self.in_dim = 0
        self.out = []

if __name__ == "__main__":
    nodes = []

    # initialize nodes
    with open(args.input_file) as reader:
        N: int = int(reader.readline())

        for idx in range(N):
            nodes.append(Node(idx))

        for line in reader.readlines():
            from_to: List[Node] = list(map(lambda x: nodes[int(x)], line.split(" ")))
            from_to[1].in_dim += 1
            from_to[0].out.append(from_to[1])

            print("{} {}".format(from_to[0].idx, from_to[1].idx))

    queue = []

    for node in nodes:
        if node.in_dim <= 0:
            queue.append(node)
    
    # topological sort
    result = []
    while len(queue) > 0:
        temp_node = queue.pop(0)
        result.append(temp_node)

        for out_node in temp_node.out:
            out_node.in_dim -= 1
            if out_node.in_dim <=0:
                queue.append(out_node)

    if len(result) != len(nodes):
        print("Unable to topologically sort")
    else:
        print("Topologically sorted !!")

        for node in result:
            print(node.idx, end=" ")
