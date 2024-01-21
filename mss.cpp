//비트 마스크로 극대 안정 집합의 개수 구하기
#include <iostream>
using namespace std;
int solve();
void precalc();

const int m = 7;
int explode[m]; //m비트 정수 m개

int main() {
	precalc();
	cout << solve();
}

int solve() {
	int count = 0;
	for (int set = 1; set < (1 << m); set++) {
		int a = 0;
		for (int i = 0; i < m; i++)
			if (set & (1 << i))
				a |= explode[i];
		if (a == ~set) count++;
	}
	return count;
}

void precalc() {
	explode[0] = 22;
	explode[1] = 9;
	explode[2] = 33;
	explode[3] = 1;
	explode[4] = 33;
	explode[5] = 20;
	explode[6] = 0;
}