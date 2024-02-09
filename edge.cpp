//DFS 스패닝 트리의 간선 구분 (유향 그래프)
#include <iostream>
#include <vector>
using namespace std;

const int N;
vector<vector<int>> adj;
vector<int> visited;
vector<bool> finished;
vector<vector<int>> edge;
int counter;
void dfs(int here) {
	visited[here] = counter++;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		int& edg = edge[here][there];
		if (!visited[there]) { //tree edge
			edg = 1;
			dfs(there);
		}
		else if (visited[here] < visited[there]) //forward edge
			edg = 2;
		else if (!finished[there]) //back edge
			edg = 3;
		else //cross edge
			edg = 4;
	}
	finished[here] = true;
}

void start() {
	adj = vector<vector<int>>(N);
	visited = vector<int>(N, 0);
	finished = vector<bool>(N, false);
	edge = vector<vector<int>>(N, vector<int>(N, 0));
	counter = 1;

	dfs(0);
}