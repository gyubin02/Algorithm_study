//dfs 구현 (인접 리스트, 인접 행렬)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacent; //adjacent[i] : 정점 i의 간선을 저장한 벡터
vector<bool> visited; //visited[i] : 정점 i의 방문 여부
void dfs(int here) { //O(V + E)
	cout << "Visit " << here << "\n";
	visited[here] = true;
	for (int i = 0; i < adjacent[here].size(); i++) {
		int there = adjacent[here][i];
		if (!visited[there])
			dfs(there);
	}
}

void dfsAll() {
	for (int here = 0; here < adjacent.size(); here++)
		if (!visited[here])
			dfs(here);
}

vector<vector<bool>> matrix; //matrix[i][j] : 정점 i에서 정점 j로 가는 간선의 존재 여부
void dfs_matrix(int here) { //O(V^2)
	cout << "Visit " << here << "\n";
	visited[here] = true;
	for (int there = 0; there < matrix[here].size(); there++) {
		bool poss = matrix[here][there];
		if (poss && !visited[there])
			dfs_matrix(there);
	}
}

/*
인접 행렬로 그래프를 표현하면 두 정점 사이에 간선이 존재하는지를 상수 시간에 알 수 있다.
단 간선의 개수가 정점 개수의 제곱보다 훨씬 적은 경우 메모리가 낭비되는 문제가 있다.
위 경우 dfs의 수행 시간도 인접 리스트에 비해 느리다.
*/