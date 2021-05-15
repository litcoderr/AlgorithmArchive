import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

def preOrder(tree, index):
    if index < len(tree):
        print("{} ".format(tree[index]), end='')
        preOrder(tree, 2*index)
        preOrder(tree, 2*index+1)

def inOrder(tree, index):
    if index < len(tree):
        inOrder(tree, 2*index)
        print("{} ".format(tree[index]), end='')
        inOrder(tree, 2*index+1)

def postOrder(tree, index):
    if index < len(tree):
        postOrder(tree, 2*index)
        postOrder(tree, 2*index+1)
        print("{} ".format(tree[index]), end='')


if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        N = int(f.readline())
        tree = list(map(lambda x: int(x), f.readline().split(" ")))
        tree.insert(0, -1)

    print("Pre-Order: ", end='') 
    preOrder(tree, 1)
    print("")

    print("In-Order: ", end='') 
    inOrder(tree, 1)
    print("")

    print("Post-Order: ", end='') 
    postOrder(tree, 1)
    print("")