import argparse
from binarySearch import bs

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()


if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        target = int(f.readline())
        arr = list(map(lambda x: int(x), f.readline().split(" ")))

    print("TARGET: {}".format(target))
    print("ARR: {}".format(arr))

    index = bs(target=target, arr=arr)

    if index != -1:
        print("Success!! Index: {}".format(index))
    else:
        print("Unable to find target")