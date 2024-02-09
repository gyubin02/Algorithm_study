//������ ������Ʈ ���ϱ�
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N;
vector<vector<int>> adj;
vector<int> visited, scc;
int vertexC, sccC;
stack<int> s;
//here�� ��Ʈ�� �ϴ� ����Ʈ������ ������ �����̳� ���� ������ ���� 
//�� �� �ִ� ���� �� ���� ���� �湮�� ������ �湮 ������ ��ȯ
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