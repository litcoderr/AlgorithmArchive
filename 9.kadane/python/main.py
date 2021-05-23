import sys
import argparse
from typing import List

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

def kadanes_algorithm(arr: List[int]):
    max_val = -sys.maxsize-1
    si = 0
    ei = 0

    si_ = 0
    ei_ = 0
    lm = arr[0]

    for i, val in enumerate(arr):
        if val > val+lm:
            si_ = i
        else:
            ei_ = i

        lm = max(val, val+lm)

        if lm > max_val:
            max_val = lm
            si = si_
            ei = ei_
    
    return max_val, si, ei

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        arr = []
        for line in f:
            arr.append(int(line))
    
    max_val, si, ei = kadanes_algorithm(arr)

    print("staring index: {}".format(si))
    print("ending index: {}".format(ei))
    print("max value: {}".format(max_val))
    