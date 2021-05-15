#include <iostream>

int main(int argc, char* argv[]) {
    int N;

    FILE* file = std::fopen(argv[1], "r");
    std::fscanf(file, "%d", &N);    

    return 0;
}