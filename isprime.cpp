//������ �Ҽ� �Ǻ� �˰��� && �����佺�׳׽��� ü
#include <iostream>
#include <vector>
using namespace std;
bool isPrime_simple(int n);
vector<int> primeFactorize_simple(int n);
void eratosthenes();
vector<int> primeFactorize(int n);

const int MAX_N = 500;
int sieve[MAX_N + 1]; //sieve[i] : i�� �Ҽ��� i, �Ҽ��� �ƴϸ� ���� ���� ���μ�

int main(void) {
	eratosthenes();
	int n;
	cin >> n;
	vector<int> ret;
	ret = primeFactorize(n);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}

bool isPrime_simple(int n) { //n�� �Ҽ����� ���θ� ��ȯ (O(sqrt(n))) => pseudo polynomial
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= int(sqrt(n)); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> primeFactorize_simple(int n) { //n�� ���μ� ������ ����� ��ȯ
	vector<int> ret;
	for (int div = 2; div <= int(sqrt(n)); div++)
		while (n % div == 0) {
			n /= div;
			ret.push_back(div);
		}
	if (n > 1) ret.push_back(n);
	return ret;
}

void eratosthenes() {
	for (int i = 0; i < MAX_N + 1; i++)
		sieve[i] = i;
	sieve[0] = sieve[1] = -1;
	for (int i = 2; i <= int(sqrt(MAX_N)); i++)
		if (sieve[i] == i)
			for (int j = i * i; j < MAX_N + 1; j += i)
				if (sieve[j] == j)
					sieve[j] = i;
}

vector<int> primeFactorize(int n) {
	vector<int> ret;
	while (n > 1) {
		ret.push_back(sieve[n]);
		n /= sieve[n];
	}
	return ret;
}