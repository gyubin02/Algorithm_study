//UVa Online Judge 10385�� ����
//t = �� Ʈ�� ����, r = �޸��� Ʈ�� ����, t-r = ������ Ʈ�� ����
//n-1��° ������ 1���ϵ��� r�� ���̸� ������ ��, 1��� 2���� ���� �ð� ���̰� �ִ밡 �Ǵ� Ʈ�� ���̸� ã���ÿ�
#include <iostream>
using namespace std;

int n, t;
double run[500], cycle[500];

//g(i, r) : i�� �������� ���� �ð�
//f(r) : 1��� 2���� ���� �ð� ����
double g(int i, double r) {
	return r / run[i] + (t - r) / cycle[i];
}

double f(double r) {
	double first = g(n - 1, r);
	double others = g(0, r);
	for (int i = 1; i < n - 1; i++)
		others = min(others, g(i, r));
	return others - first;
}

double search() { //f�� ���� �ش����� ���Ѵ�
	double lo = 0, hi = t;
	for (int it = 0; it < 100; it++) {
		double x = (2 * lo + hi) / 3;
		double y = (lo + 2 * hi) / 3;
		if (f(x) <= f(y))
			lo = x;
		if (f(x) >= f(y))
			hi = y;
	}
	return (hi - lo) / 2;
}