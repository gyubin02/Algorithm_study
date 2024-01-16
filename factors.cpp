//약수의 수 계산 && 유클리드
#include <iostream>
using namespace std;
void getNum();
int gcd(int p, int q);

const int MAX_N = 10000000;
int factors[MAX_N];

int main() {
	getNum();
	int p, q;
	cin >> p >> q;
	cout << gcd(p, q);
}

void getNum() {
	for (int i = 1; i <= MAX_N; i++)
		factors[i] = 0;

	for (int i = 1; i <= MAX_N; i++)
		for (int div = i; div <= MAX_N; div += i)
			factors[div]++;
}

int gcd(int p, int q) {
	return (q == 0) ? p : gcd(q, p % q);
}