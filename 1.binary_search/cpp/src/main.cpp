#include <iostream>
#include <vector>

enum Status {
    FOUND, NOTFOUND
};

typedef struct Result {
    Status status;
    int index;
} Result;

Result binary_search(int target, std::vector<int>& arr);
Result binary_search(int target, std::vector<int>& arr, int i, int j);
void print(Result& result);

int main(int argc, char* argv[]) {
    int target;
    std::vector<int> arr;

    FILE* input_file = std::fopen(argv[1], "r");
    fscanf(input_file, "%d", &target);

    int temp;
    while(fscanf(input_file, "%d", &temp) != EOF) {
        arr.push_back(temp);
    }

    printf("TARGET: %d\n", target);
    printf("ARR: ");
    for(int elem: arr) {
        printf("%d ", elem);
    }
    printf("\n");

    Result result = binary_search(target, arr);

    print(result);
    return 0;
}

Result binary_search(int target, std::vector<int>& arr) {
    return binary_search(target, arr, 0, arr.size()-1);
}

Result binary_search(int target, std::vector<int>& arr, int i, int j) {
    Result result;

    if(j<=i) { // recursion exit sequence
        if(arr[i]==target) { // found
            result = {
                Status::FOUND,
                i
            };
            return result;
        }else { // not found
            result = {
                Status::NOTFOUND,
                -1
            };
            return result;
        }
    }else { // continue recursion
        int mid = (i+j) / 2;
        if(arr[mid]==target) { // found
            result = {
                Status::FOUND,
                mid
            };
            return result;
        }else if (arr[mid]>target){ // bigger than
            return binary_search(target, arr, i, mid-1);
        }else { // less than
            return binary_search(target, arr, mid+1, j);
        }
    }
}

void print(Result& result) {
    printf("ISFOUND: %d\n", result.status);
    printf("INDEX: %d\n", result.index);
}
