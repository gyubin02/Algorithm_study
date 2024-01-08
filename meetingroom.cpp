//ȸ�ǽ� ���� ���� (Ž���)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Begin[100], End[100];

int func() { //ȸ�ǽ� ���� �� ���� �ִ밪
	vector<pair<int, int>> order;
	for (int i = 0; i < 100; i++)
		order.push_back(make_pair(End[i], Begin[i]));
	sort(order.begin(), order.end()); //O(NlogN)
	int last_endTime = 0; //�������� ������ ���� ȸ�� ���� �ð�
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		int beginTime = order[i].second;
		int endTime = order[i].first;
		if (last_endTime > beginTime) continue;
		last_endTime = endTime;
		ret++;
	}
	return ret;
}