//문자열 검색 알고리즘
#include <iostream>
#include <vector>
using namespace std;

vector<int> naiveSearch(const string& haystack, const string& needle) { //O(HN)
	int H = haystack.size();
	int N = needle.size();
	vector<int> ret;
	for (int i = 0; i <= H - N; i++) {
		bool isHere = true;
		for (int j = 0; j < N; j++)
			if (haystack[i + j] != needle[j]) {
				isHere = false;
				break;
			}
		if (isHere) ret.push_back(i);
	}
	return ret;
}