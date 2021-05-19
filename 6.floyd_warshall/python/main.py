import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

SOME_MAX_NUM = 987654321

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        V, E = tuple(map(lambda x: int(x), f.readline().split(" ")))

        arr = [[SOME_MAX_NUM  if i != j else 0 for i in range(V)] for j in range(V)]

        for line in f:
            v_from, v_to, weight = tuple(map(lambda x: int(x), line.split(" ")))
            arr[v_from][v_to] = weight

    for v_from in range(V):
        for v_to in range(V):
            for v_via in range(V):
                via_weight = arr[v_from][v_via] + arr[v_via][v_to]

                if via_weight < arr[v_from][v_to]:
                    arr[v_from][v_to] = via_weight

    have_neg_cycle = False
    for v_index in range(V):
        if arr[v_index][v_index] < 0:
            have_neg_cycle = True
            break 
    
    if have_neg_cycle:
        print("have negative cycle!!")
    else:
        print(arr)
        