//회의실 예약 문제 (탐욕법)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Begin[100], End[100];

int func() { //회의실 배정 팀 수의 최대값
	vector<pair<int, int>> order;
	for (int i = 0; i < 100; i++)
		order.push_back(make_pair(End[i], Begin[i]));
	sort(order.begin(), order.end()); //O(NlogN)
	int last_endTime = 0; //마지막에 배정된 팀의 회의 종료 시간
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