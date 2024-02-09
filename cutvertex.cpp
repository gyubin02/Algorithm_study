//���� �׷����� ������ ã��
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<bool> cutVertex;
int counter;

int func(int here, bool isRoot) { //here�� ��Ʈ�� �ϴ� ����Ʈ���� �ִ�� �ö� �� �ִ� ������ ��ȣ�� ��ȯ
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