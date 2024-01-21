//bool 배열 대신 비트마스크 사용하기
#include <iostream>
using namespace std;
void eratosthenes();
void eratosthenes_mask();

const int MAX_N = 101; //(0~100)
bool sieve[MAX_N]; //N칸 필요, i가 소수면 sieve[i] = true
char sieve_mask[(MAX_N + 7) / 8]; //(N/8)칸 필요, i가 소수면 sieve_mask[(i/8)]의 (i%8)번 비트가 1

int main() {
	eratosthenes();
	eratosthenes_mask();
	int x;
	while (true) {
		cin >> x;
		if (x == -1) break;
		char r = sieve_mask[x >> 3] & (1 << (x & 7));
		cout << sieve[x] << " " << (r!=0) << "\n";
	}
}

//1 이상 100 이하의 자연수 각각이 소수인지 아닌지 배열에 저장
void eratosthenes() {
	for (int i = 2; i < MAX_N; i++)
		sieve[i] = true;

	for (int i = 2; i <= (int)sqrt(MAX_N - 1); i++)
		if (sieve[i] == true)
			for (int j = i * i; j < MAX_N; j += i)
				sieve[j] = false;
}

void eratosthenes_mask() {
	int n = (MAX_N + 7) / 8;
	for (int i = 2; i < n; i++)
		sieve_mask[i] = (1 << 8) - 1;

	for (int i = 2; i <= (int)sqrt(n); i++)
		if (sieve_mask[i >> 3] & (1 << (i & 7)))
			for (int j = i * i; j < n; j += i)
				sieve_mask[j >> 8] &= ~(1 << (j & 7));
}