//�޸������̼����� ���� ��� ���ϱ�
#include <iostream>
using namespace std;
int comb(int n, int r);

int cache[30][30];

int main() {
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			cache[i][j] = -1;
}

int comb(int n, int r) { //n >= r�̶�� �����մϴ�.
	if (r == 0 || r == n) return 1;
	if (cache[n][r] != -1) return cache[n][r];
	return cache[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}
