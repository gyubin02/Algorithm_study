//원형 문자열 예제
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
string solve(const string& s);
vector<int> getSuffixArray(const string& s);

int main() {
	string s;
	cin >> s;
	cout << solve(s);
}

string solve(const string& s) {
	int n = s.size();
	string s2 = s + s;
	vector<int> arr = getSuffixArray(s2);
	for (int i = 0; i < arr.size(); i++)
		if (arr[i] <= n) return s2.substr(arr[i], s.size());
	return "You can't be here";
}

vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	vector<int> ret(n), group(n + 1);
	group[n] = -1;
	for (int i = 0; i < n; i++)
		ret[i] = i;
	for (int i = 0; i < n; i++)
		group[i] = s[i];
	int t = 1;
	while (t < n) {
		Comparator comp(t, group);
		sort(ret.begin(), ret.end(), comp);
		t *= 2;
		if (t >= n) break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[ret[0]] = 0;
		for (int i = 1; i < n; i++)
			if (comp(ret[i - 1], ret[i]))
				newGroup[ret[i]] = newGroup[ret[i - 1]] + 1;
			else
				newGroup[ret[i]] = newGroup[ret[i - 1]];
		group = newGroup;
	}
	return ret;

}
