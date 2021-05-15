import argparse
from bfs_dfs import bfs, dfs, Node

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()


if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        N = int(f.readline())

        nodes = []
        for i in range(N):
            nodes.append(Node(i))

        while True:
            line = f.readline()
            if not line:
                break
            else:
                n_a, n_b = tuple(map(lambda x: int(x), line.split(" ")))
                nodes[n_a].adj.append(nodes[n_b])
                nodes[n_b].adj.append(nodes[n_a])

        bfs_order = []
        bfs(0, nodes, bfs_order)
        print("BFS order: {}".format(bfs_order)) 

        dfs_order = []
        dfs(0, nodes, dfs_order)
        print("DFS order: {}".format(dfs_order)) 