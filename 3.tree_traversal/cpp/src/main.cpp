#include <iostream>

void inOrder(int* tree, int N, int idx);
void preOrder(int* tree, int N, int idx);
void postOrder(int* tree, int N, int idx);

int main(int argc, char* argv[]) {
    int N;
    int* tree;

    FILE* file = std::fopen("../test.txt", "r");
    fscanf(file, "%d", &N);
    
    tree = new int[N+1];

    for(int i=1; i<=N; i++) {
        fscanf(file, "%d", tree+i);
    }

    // in-order (left -> root -> right)
    printf("in-order: ");
    inOrder(tree, N, 1);
    printf("\n");

    // pre-order (root -> left -> right)
    printf("pre-order: ");
    preOrder(tree, N, 1);
    printf("\n");

    //post-order (left -> right -> root)
    printf("post-order: ");
    postOrder(tree, N, 1);
    printf("\n");

    return 0;
}

void inOrder(int* tree, int N, int idx) { // (left -> root -> right)
    if(idx <= N) {
        inOrder(tree, N, 2 * idx);
        printf("%d ", tree[idx]);
        inOrder(tree, N, 2 * idx + 1);
    }
}

void preOrder(int* tree, int N, int idx) { // (root-> left -> right)
    if(idx <= N) {
        printf("%d ", tree[idx]);
        preOrder(tree, N, 2 * idx);
        preOrder(tree, N, 2 * idx + 1);
    }
}

void postOrder(int* tree, int N, int idx) { // (left -> right -> root)
    if(idx <= N) {
        postOrder(tree, N, 2 * idx);
        postOrder(tree, N, 2 * idx + 1);
        printf("%d ", tree[idx]);
    }
}