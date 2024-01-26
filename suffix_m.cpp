//맨버-마이어스 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct suffixComparator {
	int t;
	vector<int>& group;
	suffixComparator(int t, vector<int>& group) :t(t),group(group) {}
	bool operator()(int i, int j) {
		if (group[i] != group[j])
			return group[i] < group[j];
		return group[i + t] < group[j + t];
	}
};
vector<int> getSuffixArray(const string& s);

int main() {
	string s;
	cin >> s;
	vector<int> ret = getSuffixArray(s);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";
}

vector<int> getSuffixArray(const string& s) {
	int N = s.size();
	vector<int> ret(N), group(N + 1);
	group[N] = -1;
	for (int i = 0; i < N; i++)
		ret[i] = i;
	for (int i = 0; i < N; i++)
		group[i] = s[i];
	int t = 1;
	while(t < N) {
		suffixComparator comp = suffixComparator(t, group);
		sort(ret.begin(), ret.end(), comp);
		t *= 2;
		if (t >= N) break;
		vector<int> newGroup(N + 1);
		newGroup[ret[0]] = 0;
		newGroup[N] = -1;
		for (int j = 1; j < N; j++) 
			if (comp(ret[j - 1], ret[j]))
				newGroup[ret[j]] = newGroup[ret[j - 1]] + 1;
			else
				newGroup[ret[j]] = newGroup[ret[j - 1]];
		group = newGroup;
	}
	return ret;
}
