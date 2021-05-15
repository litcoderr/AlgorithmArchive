import argparse
from random import randrange
from multiprocessing import Process, Array

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

def mergeSort(arr):
    mergeSort_(0, arr, 0, len(arr)-1)

def mergeSort_(id, arr, i, j):
    if j-i > 0:
        median = (i+j) // 2
        left_merge = Process(target=mergeSort_,
                         args=(0, arr, i, median))
        right_merge = Process(target=mergeSort_,
                              args=(0, arr, median+1, j))
        
        left_merge.start()
        right_merge.start()

        left_merge.join()
        right_merge.join()

        # when merging of child segements is finished
        # merge child segments to parent

        parent_merge = Process(target=merge, args=(0, arr, i, median, j))
        parent_merge.start()
        parent_merge.join()

def merge(id, arr, i, median, j):
    temp = [0 for _ in range(j-i+1)]

    index = 0
    l_index = i
    r_index = j

    while l_index <= median and r_index <= j:
        if arr[l_index] < arr[r_index]:
            temp[index] = arr[l_index]
            l_index += 1
        else:
            temp[index] = arr[r_index]
            r_index += 1
        index +=1
    
    while l_index <= median:
        temp[index] = arr[l_index]
        index += 1
        l_index += 1
    
    while r_index <= j:
        temp[index] = arr[r_index]
        index += 1
        r_index += 1
    
    for i_ in range(0, j-i+1):
        arr[i+i_] = temp[i_]
        

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        N = int(f.readline())

    # initialize arr with random values
    initial_arr = [randrange(10000) for _ in range(N)]
    arr = Array('i', initial_arr)
    print(list(arr))

    mergeSort(arr)

    print(list(arr))