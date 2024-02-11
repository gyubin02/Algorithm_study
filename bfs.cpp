//너비 우선 탐색
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N;
vector<vector<int>> adj; //인접 리스트
vector<int> distancee, parent;
void bfs(int s) {
	distancee = vector<int>(N, -1);
	parent = vector<int>(N, -1);
	queue<int> q;
	q.push(s);
	distancee[s] = 0;
	parent[s] = s;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << "visit : " << here << "\n";
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (distancee[there] == -1) {
				q.push(there);
				distancee[there] = distancee[here] + 1;
				parent[there] = here;
			}
		}
	}
}

vector<int> shortestPath(int v, vector<int>& parent) { //bfs 스패닝 트리 parent와 정점 v가 주어질 때, v부터 루트까지의 경로를 반환
	vector<int> path(1, v);
	int p = path[0];
	while (true) {
		p = parent[p];
		path.push_back(p);
		if (parent[p] == p) break;
	}
	return path;
}