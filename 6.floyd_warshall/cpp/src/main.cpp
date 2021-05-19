#include <iostream>
#include <climits>

#define BIG_INT (123456789)

int main(int argc, char* argv[]) {
    int V, E;
    FILE* file = std::fopen("../test.txt", "r");

    std::fscanf(file, "%d %d", &V, &E);

    int** arr = new int*[V];
    for(int i=0;i<V;i++) {
        arr[i] = new int[V];
        for(int j=0;j<V;j++) {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = BIG_INT;
        }
    }

    int from, to, weight;
    while(std::fscanf(file, "%d %d %d", &from, &to, &weight) != EOF) {
        arr[from][to] = weight;
    } 

    for(int from=0;from<V;from++) {
        for(int to=0;to<V;to++) {
            for(int via=0;via<V;via++) {
                int via_dist = arr[from][via] + arr[via][to];
                if(arr[from][to] > via_dist) {
                    arr[from][to] = via_dist;
                }
            }
        }
    }

    bool has_negative_loop = false;
    for(int i=0;i<V;i++) {
        if(arr[i][i]<0) has_negative_loop = true;
    }

    if(has_negative_loop) printf("has negative loop\n");
    else {
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                if(arr[i][j]!=BIG_INT) {
                    printf("%10d ", arr[i][j]);
                }else {
                    printf("         x ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
