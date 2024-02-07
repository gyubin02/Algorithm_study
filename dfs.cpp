//dfs ���� (���� ����Ʈ, ���� ���)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacent; //adjacent[i] : ���� i�� ������ ������ ����
vector<bool> visited; //visited[i] : ���� i�� �湮 ����
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

vector<vector<bool>> matrix; //matrix[i][j] : ���� i���� ���� j�� ���� ������ ���� ����
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
���� ��ķ� �׷����� ǥ���ϸ� �� ���� ���̿� ������ �����ϴ����� ��� �ð��� �� �� �ִ�.
�� ������ ������ ���� ������ �������� �ξ� ���� ��� �޸𸮰� ����Ǵ� ������ �ִ�.
�� ��� dfs�� ���� �ð��� ���� ����Ʈ�� ���� ������.
*/