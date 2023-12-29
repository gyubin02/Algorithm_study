//메모이제이션으로 이항 계수 구하기
#include <iostream>
using namespace std;
int comb(int n, int r);

int cache[30][30];

int main() {
	memset(cache, -1, sizeof(cache));
	cout << comb(4, 2);
}

int comb(int n, int r) { //n >= r이라고 가정합니다.
	if (r == 0 || r == n) return 1;
	int& ret = cache[n][r];
	if (ret != -1) return ret;
	return ret = comb(n - 1, r - 1) + comb(n - 1, r);
}
