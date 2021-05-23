#include <iostream>
#include <climits>
#include <vector>

void kadanes_algorithm(std::vector<int>& arr, int& si, int& ei, int& max_val);

int main(int argc, char* argv[]) {
    FILE* file = std::fopen(argv[1], "r");

    std::vector<int> arr;

    int num;
    while(std::fscanf(file, "%d", &num)!=EOF) {
        arr.push_back(num);
    }

    int si, ei;
    int max_val = INT_MIN;
    kadanes_algorithm(arr, si, ei, max_val);

    std::printf("starting index: %d\n", si);
    std::printf("ending index: %d\n", ei);
    std::printf("max value: %d\n", max_val);

    return 0;
}

int max(int a, int b) {
    return a>b? a: b;
}

void kadanes_algorithm(std::vector<int>& arr, int& si_, int& ei_, int& max_val) {
    int si = 0; // starting index
    int ei = 0; // ending index
    std::vector<int> lm; // local maximum

    for(int i=0;i<arr.size();i++) {
        if(i==0) lm.push_back(arr[i]);
        else lm.push_back(0);
    }

    for(int i=1;i<arr.size();i++) {
        lm[i] = max(arr[i], arr[i]+lm[i-1]);
        if(arr[i] > arr[i]+lm[i-1]) si = i;
        else ei = i;

        if(lm[i] > max_val) {
            max_val = lm[i];
            si_ = si;
            ei_ = ei;
        }
    }
}