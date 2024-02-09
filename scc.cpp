//강결합 컴포넌트 구하기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N;
vector<vector<int>> adj;
vector<int> visited, scc;
int vertexC, sccC;
stack<int> s;
//here를 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을 통해 
//갈 수 있는 정점 중 가장 먼저 방문한 정점의 방문 순서를 반환
int func(int here) { 
	s.push(here);
	visited[here] = vertexC++;
	int ret = visited[here];
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			ret = min(ret, func(there));
		else if (!scc[there])
			ret = min(ret, visited[there]);
	}
	if (ret == visited[here]) {
		while (true) {
			int t = s.top();
			s.pop();
			scc[t] = sccC;
			if (t == here) break;
		}
		sccC++;
	}
	return ret;
}

void start() {
	visited = vector<int>(N, 0);
	scc = vector<int>(N, 0);
	vertexC = sccC = 1;
	for (int i = 0; i < adj.size(); i++)
		if (!visited[i])
			func(i);
}