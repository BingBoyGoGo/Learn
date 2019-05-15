#if 1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node {
	int num;
	bool visit;
};

using namespace std;

// initialize
bool G[10][10] = { {0,0,0,0,0,0,0,0,1,0},
					{0,0,1,1,0,0,0,1,0,1},
					{0,1,0,0,1,0,0,0,1,0},
					{0,1,0,0,1,1,0,0,0,0},
					{0,0,1,1,0,0,0,0,0,0},
					{0,0,0,1,0,0,1,0,0,1},
					{0,0,0,0,0,1,0,1,0,0},
					{0,1,0,0,0,0,1,0,0,0},
					{1,0,1,0,0,0,0,0,0,1},
					{0,1,0,0,0,0,0,0,1,0} };

// see if vertex was visit
bool visit[10] = { false };

// the path to vertex & sourceVertex
int sourceVertex = 2;
int path[] = { 0,0,2,0,0,0,0,0,0,0 };

// Print Path to the target(BFS)
int PrintPath(int dist) {
	vector<int> arr;
	int x = dist;
	while (sourceVertex != x) {
		arr.push_back(x);
		x = path[x];
	}
	arr.push_back(sourceVertex);
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr.back() << std::endl;
	return 0;
}

// Print Path to target(DFS)
int PrintPath(vector<int> path) {
	for (int i = 0; i < path.size() - 1; i++) {
		std::cout << path[i] << ", ";
	}
	std::cout << path.back() << std::endl;
	return 0;
}

// BFS
int BFS(int targetVertex) {
	queue<int> q;
	// push source vertex
	q.push(sourceVertex);
	while (!q.empty()) {
		int vertex = q.front();
		visit[vertex] = true;

		for (int i = 0; i < 10; i++) {
			if (G[vertex][i] && (i == targetVertex)) {
				// find target, change path
				path[i] = vertex;
				PrintPath(i);
				return 0;
			}
			if (G[vertex][i] & !visit[i]) { // find a vertex
				q.push(i);
				// change path & visit
				path[i] = vertex;
				visit[i] = true;
			}
		}
		q.pop();
	}

	std::cout << "CANNOT FIND v" << targetVertex << std::endl;

	return 0;
}

// DFS
int DFS(int targetVertex) {
	vector<int> DFSpath;
	// source vertex is v2
	DFSpath.push_back(sourceVertex);
	int vertex;
	bool flag = false;	// find a new vertex
	while (!DFSpath.empty()) {
		vertex = DFSpath.back();
		visit[vertex] = true;
		for (int i = 9; i >= 0; i--) {
			if (G[vertex][i] && i == targetVertex) {
				// find target
				DFSpath.push_back(i);
				PrintPath(DFSpath);
				return 0;
			}
			if (G[vertex][i] && !visit[i]) {
				// find a vertex
				flag = true;
				DFSpath.push_back(i);
				break;
			}
		}
		if (!flag) {
			// cannot find the next vertex
			DFSpath.pop_back();
		}
		flag = false;
	}

	std::cout << "CANNOT FIND v" << targetVertex << std::endl;
	return 0;
}



int main() {
	int targetVertex = 0;
	while (true) {
		std::cout << "input the target vertex: ";
		std::cin >> targetVertex;
		if (targetVertex > 9 || targetVertex < 0) {
			std::cout << "cannot find v" << targetVertex << std::endl;
		}
		else if (targetVertex == sourceVertex) {
			std::cout << "use BFS: " << sourceVertex << std::endl;
			std::cout << "use DFS: " << sourceVertex << std::endl;
		}
		else {
			std::cout << "use BFS: ";
			BFS(targetVertex);
			for (int i = 0; i < 10; i++) {
				visit[i] = false;
				path[i] = 0;
			}
			path[sourceVertex] = sourceVertex;

			std::cout << "use DFS: ";
			DFS(targetVertex);
			for (int i = 0; i < 10; i++) {
				visit[i] = false;
			}
		}
	}
	return 0;
}
#endif