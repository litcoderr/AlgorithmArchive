#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread>

#define NUM_MAX (10000)

void multithreaded_mergesort(int N, int* arr);
void merge_sort_(int N, int* arr, int i, int j);
void merge(int* arr, int i, int median, int j);

int main(int argc, char* argv[]) {
    std::srand(std::time(NULL));

    int N;
    int* arr;

    FILE* file = std::fopen(argv[1], "r");
    std::fscanf(file, "%d", &N);    

    // Initialize random array
    arr = new int[N];
    for (int i=0;i<N;i++) {
        arr[i] = std::rand() % NUM_MAX;
    }

    // merge sort
    multithreaded_mergesort(N, arr);

    for(int i=0;i<N;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    delete[] arr;
    return 0;
}

void multithreaded_mergesort(int N, int* arr) {
    merge_sort_(N, arr, 0, N-1);
}

void merge_sort_(int N, int* arr, int i, int j) {
    if(j-i>0) {
        int median = (i+j)/2;
        std::thread left_merge(merge_sort_, N, arr, i, median);
        std::thread right_merge(merge_sort_, N, arr, median+1, j);

        left_merge.join();
        right_merge.join();

        // when merging of child segements is finished
        // merge child segments to parent

        std::thread parent_merge(merge, arr, i, median, j);
        parent_merge.join();
    }
}

void merge(int* arr, int i, int median, int j) {
    int * temp = new int[j-i+1];

    int index = 0;
    int l_index = i;
    int r_index = median+1;

    while (l_index<=median && r_index<=j) {
        if(arr[l_index] < arr[r_index]) {
            temp[index] = arr[l_index];
            l_index++;
        }else {
            temp[index] = arr[r_index];
            r_index++;
        }
        index++;
    }

    while(l_index<=median) {
        temp[index] = arr[l_index];
        index++;
        l_index++;
    }

    while(r_index<=j) {
        temp[index] = arr[r_index];
        index++;
        r_index++;
    }

    for(int index=0;index<(j-i+1);index++) {
        arr[i+index] = temp[index];
    }

    delete[] temp;
}
