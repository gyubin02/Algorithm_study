//���� ��ȹ���� �̿��� Ȯ�� ���
#include <iostream>
using namespace std;
int func(int days, int sum);

const int MAX_DAYS = 30;
int days, m;
int cache1[MAX_DAYS][MAX_DAYS * 2];

int main() {
	for (int i = 0; i < MAX_DAYS; i++)
		for (int j = 0; j < MAX_DAYS * 2; j++)
			cache1[i][j] = -1;

	cin >> days >> m;
	cout << func(days, 0) / pow(2, days);
}

int func(int days, int sum) { //�����̰� days�� �� ���� m - sum �̻� �ö󰡴� ����� ��
	//base : if(days == 0) return (sum >= m);
	//step : func(days, sum) = func(days-1, sum+1) + func(days-1, sum+2)

	//base
	if (days == 0) return (sum >= m);
	//check memo
	int& ret = cache1[days][sum];
	if (ret != -1) return ret;
	//step
	return ret = func(days - 1, sum + 1) + func(days - 1, sum + 2);
}