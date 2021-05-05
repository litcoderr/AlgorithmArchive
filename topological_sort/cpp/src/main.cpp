#include <iostream>
#include <queue>
#include "node.hpp"

int main(int argc, char* argv[]) {
	// read test file
	FILE* input_file = std::fopen(argv[1], "r");
	int N;
	fscanf(input_file, "%d\n", &N);

	Node* nodes = new Node[N];
	int from, to;
	while(fscanf(input_file, "%d", &from)!=EOF) {
		fscanf(input_file, "%d", &to);
		printf("from: %d to: %d\n", from, to);

		nodes[from].to.push_back(nodes+to);
		nodes[to].in_dim += 1;
		nodes[to].temp += 1;
	}

	// sort
	//TODO fix bug
	std::queue<int> que;
	for(int i=0;i<N;i++) {
		if (nodes[i].temp==0) {
			que.push(i);
		}
	}

	int sorted = 0;
	while(que.size()>0) {
		printf("%d\n", que.front());
	}

	return 0;
}
