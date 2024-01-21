//��Ʈ ����ũ�� �ش� ���� ������ ���� ���ϱ�
#include <iostream>
using namespace std;
int solve();
void precalc();

const int m = 7;
int explode[m]; //m��Ʈ ���� m��

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