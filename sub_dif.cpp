//���� �ٸ� �κ� ���ڿ��� ���� ���ϱ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Comparator {
	int t;
	vector<int>& group;
	Comparator(int t, vector<int>& group):t(t),group(group){}
	bool operator()(int i, int j) {
		if (group[i] != group[j])
			return group[i] < group[j];
		return group[i + t] < group[j + t];
	}
};
vector<int> getSuffixArray(const string& S);
int getPrefix(const string& S, int i, int j);
int solve(const string& S);

vector<int> getSuffixArray(const string& S) {
	vector<int> group(S.size() + 1), ret(S.size());
	group[S.size()] = -1;
	for (int i = 0; i < S.size(); i++) {
		group[i] = S[i];
		ret[i] = i;
	}
	int t = 1;
	while (t < S.size()) {
		Comparator comp(t, group);
		sort(ret.begin(), ret.end(), comp);
		t *= 2;
		if (t >= S.size()) break;
		vector<int> newGroup(S.size() + 1);
		newGroup[S.size()] = -1;
		newGroup[ret[0]] = 0;
		for (int i = 1; i < S.size(); i++) {
			if (comp(ret[i - 1], ret[i]))
				newGroup[ret[i]] = newGroup[ret[i - 1]] + 1;
			else
				newGroup[ret[i]] = newGroup[ret[i - 1]];
		}
		group = newGroup;
	}
	return ret;
}

int getPrefix(const string& S, int i, int j) {
	int matched = 0;
	while (i < S.size() && j < S.size() && S[i] == S[j]) {
		i++; j++; matched++;
	}
	return matched;
}

int solve(const string& S) {
	vector<int> arr = getSuffixArray(S);
	int ret = 0;
	ret += S.size() - arr[0];
	for (int i = 1; i < arr.size(); i++) {
		int dup = getPrefix(S, arr[i-1], arr[i]);
		ret += S.size() - arr[i] - dup;
	}
	return ret;
}

int main() {
	cout << solve("banana");
}