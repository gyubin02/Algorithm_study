//무향 그래프의 절단점 찾기
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<bool> cutVertex;
int counter;

int func(int here, bool isRoot) { //here를 루트로 하는 서브트리가 최대로 올라갈 수 있는 정점의 번호를 반환
	visited[here] = counter++;
	int ret = visited[here];
	int children = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			children++;
			int sub = func(there, false);
			if (!isRoot && sub >= visited[here])
				cutVertex[here] = true;
			ret = min(ret, sub);
		}
		else
			ret = min(ret, visited[there]);
	}
	if (isRoot)
		cutVertex[here] = (children >= 2);
	return ret;
}