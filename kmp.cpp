//KMP 알고리즘
#include <iostream>
#include <vector>
using namespace std;
vector<int> func(const string& H, const string& N);
vector<int> getP(const string& N);

int main() {
	string a = "aabaabcfgaab";
	string b = "aab";
	vector<int> ret = func(a, b);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}

vector<int> func(const string& H, const string& N) { //O(|H|)
	vector<int> p = getP(N), ret;
	int begin = 0, matched = 0;
	while (begin <= H.size() - N.size()) {
		for (; matched < N.size(); matched++)
			if (H[begin + matched] != N[matched])
				break;
		if (matched == N.size()) ret.push_back(begin);
		if (matched == 0) begin++;
		else {
			begin += (matched - p[matched - 1]);
			matched = p[matched - 1];
		}
	}
	return ret;
}

vector<int> getP(const string& N) {
	vector<int> ret(N.size(), 0);
	int begin = 1, matched = 0;
	while (begin < N.size()) {
		for (; begin + matched < N.size(); matched++) {
			if (N[begin + matched] != N[matched])
				break;
			ret[begin + matched] = matched + 1;
		}
		if (matched == 0) begin++;
		else {
			begin += (matched - ret[matched - 1]);
			matched = ret[matched - 1];
		}
	}
	return ret;
}