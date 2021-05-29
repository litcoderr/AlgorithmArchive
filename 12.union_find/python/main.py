class Node:
    def __init__(self, index: int):
        self.index: int= index
        self.parent: Node = self
        self.child: List[Node] = []

def union_(to: Node, from_: Node):
    # union from_'s child nodes to to node
    for child in from_.child:
        child.parent = to
        to.child.append(child)
    
    # union from_ node to to node
    from_.parent = to
    from_.child = []
    to.child.append(from_)

def union(n1: Node, n2: Node):
    p1 = n1.parent
    p2 = n2.parent

    # union set that has less child nodes
    if len(p1.child) < len(p2.child): union_(p2, p1)
    else: union_(p1, p2)

def visualize_set(n: Node):
    parent = n.parent
    print("{}".format(parent.index))
    
    for idx, child in enumerate(parent.child):
        if idx == len(parent.child)-1:
            print("{}".format(child.index))
        else:
            print("{} | ".format(child.index), end='')

if __name__ == "__main__":
    N: int = 10
    nodes = [Node(i) for i in range(N)]

    # union first set
    union(nodes[0], nodes[1])
    union(nodes[2], nodes[1])
    union(nodes[2], nodes[3])
    union(nodes[0], nodes[4])

    visualize_set(nodes[0])

    # union second set
    union(nodes[5], nodes[6])
    union(nodes[6], nodes[7])
    union(nodes[6], nodes[8])
    union(nodes[5], nodes[9])

    visualize_set(nodes[5])

    # union first and second set to one
    union(nodes[2], nodes[8])

    visualize_set(nodes[0])
    