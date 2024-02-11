//너비 우선 탐색
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N;
vector<vector<int>> adj; //인접 리스트
vector<bool> discovered;
void bfs(int s) {
	discovered = vector<bool>(N, false);
	queue<int> q;
	q.push(s);
	discovered[s] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << "visit : " << here << "\n";
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}