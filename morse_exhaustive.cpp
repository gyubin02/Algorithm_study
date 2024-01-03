//모스 부호 사전순 출력 (완전 탐색 이용)
#include <iostream>
using namespace std;
void generate(int n, int m, string s);

int n, m, skip;

int main() {
	int k;
	cin >> n >> m >> k;
	skip = k - 1;
	string s = "";
	generate(n, m, s);
}

void generate(int n, int m, string s) { //더 써야 하는 장점의 수 : n개,  더 써야 하는 단점의 수 : m개
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if(skip == 0) cout << s << "\n";
		skip--;
		return;
	}
	if (n > 0) generate(n - 1, m, s + '-');
	if (m > 0) generate(n, m - 1, s + 'o');
}