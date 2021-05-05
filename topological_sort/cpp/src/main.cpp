#include <iostream>
#include <queue>
#include "node.hpp"

int main(int argc, char* argv[]) {
	// read test file
	FILE* input_file = std::fopen(argv[1], "r");
	// Number of Nodes
	int N;
	fscanf(input_file, "%d\n", &N);

	Node* nodes = new Node[N];
	for(int i=0;i<N;i++) {
		nodes[i].idx = i;
	}

	int from, to;
	while(fscanf(input_file, "%d", &from)!=EOF) {
		fscanf(input_file, "%d", &to);
		printf("from: %d to: %d\n", from, to);

		// Update Node
		nodes[from].to.push_back(nodes+to);
		nodes[to].in_dim += 1;
		nodes[to].temp += 1;
	}

	// sort
	std::queue<Node*> que;
	for(int i=0;i<N;i++) {
		if (nodes[i].temp==0) {
			que.push(nodes+i);
		}
	}

	std::vector<Node*> result;
	while(que.size()>0) {
		Node* node = que.front();
		result.push_back(node);
		que.pop();

		for(Node* node_to : node->to) {
			node_to->temp--;
			if(node_to->temp<=0) {
				que.push(node_to);
			}
		}
	}

	if(result.size()!=N) {
		printf("Unable to topologically sort !!");
	}else {
		printf("Topologically Sorted !!\n");
		for(int i=0;i<N;i++) {
			printf("%d ", nodes[i].idx);
		}
		printf("\n");
	}

	return 0;
}
