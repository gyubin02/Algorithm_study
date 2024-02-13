//���� ID : HANOI4B
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 4000001;
vector<int> c(MAX);
vector<int> getTop(int state) {
	vector<int> ret(4, 999); //ret[i] = i�� ����� �� �� ���� ��ȣ
	for (int i = 0; i < 12; i++) {
		int x = (state >> i * 2) & 3;
		ret[x] = min(ret[x], 11 - i);
	}
	return ret;
}

vector<int> getAdjacent(int state) { //state�� ������ ���¸� ��ȯ
	vector<int> ret;
	vector<int> top = getTop(state);
	for (int tower = 0; tower < top.size(); tower++) {
		int ring = top[tower]; //tower�� ����� �� �� ���� ��ȣ
		if (ring == 999) continue;
		for (int i = 0; i <= 3; i++) { //ring�� ������ i�� ������� �ű�� ��
			if (tower == i) continue;
			if (ring > top[i]) continue;
			int next = (state & (0 << (11 - ring) * 2)) | (i << (11 - ring) * 2);
			ret.push_back(next);
		}
	}
}

int bfs(int start, int end) { //start ���¿��� end ���·� ���� �ִ� �Ÿ� ��ȯ
	if (start == end) return 0;
	c = vector<int>(MAX, -1);
	queue<int> q;
	q.push(start);
	c[start] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		vector<int> next = getAdjacent(here);
		for (int i = 0; i < next.size(); i++) {
			if (c[next[i]] != -1) continue;
			if (next[i] == end) return c[here] + 1;
			q.push(next[i]);
			c[next[i]] = c[here] + 1;
		}
		next.clear();
	}
	cout << "Wait? What?" << "\n";
	return -1;
}

int bidirect(int start, int end) {
	if (start == end) return 0;
	c = vector<int>(MAX, 0);
	queue<int> q;
	q.push(start);
	q.push(end);
	c[start] = 1;
	c[end] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		vector<int> next = getAdjacent(here);
		for (int i = 0; i < next.size(); i++) {
			if (c[next[i] == 0]) {
				q.push(next[i]);
				c[next[i]] = c[here] + (c[here] > 0) ? 1 : -1;
			}
			else if(c[here] * c[next[i]] < 0)
				return abs(c[here]) + abs(c[next[i]]) - 1;
		}
		next.clear();
	}
	cout << "Wait? What?" << "\n";
	return -1;
}