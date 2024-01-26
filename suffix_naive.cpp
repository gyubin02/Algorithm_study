//접미사 배열 구하기 (naive)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct suffixComparator {
	const string& s;
	suffixComparator(const string& str):s(str){}
	bool operator()(int i, int j) {
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
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

vector<int> getSuffixArray(const string& s) { //O(N^2*lgN)
	int N = s.size();
	vector<int> ret(N);
	for (int i = 0; i < N; i++)
		ret[i] = i;
	sort(ret.begin(), ret.end(), suffixComparator(s));
	return ret;
}