//피보나치 수열 - 슬라이딩 윈도우
#include <iostream>
using namespace std;
int fibo(int n);
int fibo_iterative(int n);

const int MAX_N = 20;
int cache[20];
int seq[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << fibo_iterative(n);
}

int fibo(int n) {
	//base
	if (n <= 1) return n;
	//check memo
	int& ret = cache[n];
	if (ret != -1) return ret;
	//step
	return ret = fibo(n - 2) + fibo(n - 1);
}

int fibo_iterative(int n) { //O(n)
	if (n <= 1) return n;
	seq[0] = 0;
	seq[1] = 1;
	for (int i = 2; i <= n; i++)
		seq[i % 3] = seq[(i - 2) % 3] + seq[(i - 1) % 3];
	return seq[n % 3];
}