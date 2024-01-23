//울타리 자르기 문제 - 분할 정복
#include <iostream>
using namespace std;
int func(int lo, int hi);

const int MAX_N = 20001;
int N;
int H[MAX_N];

int main() {
	int C;
	cin >> C;
	while (C-- > 0) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> H[i];
		cout << func(0, N - 1) << "\n";
	}
}

int func(int lo, int hi) {
	//base
	if (lo == hi) return H[lo];
	//step
	int mid = (lo + hi) / 2;
	//왼쪽 또는 오른쪽 절반에 있는 경우
	int cand = max(func(lo, mid), func(mid + 1, hi));
	//중간에 걸쳐 있는 경우
	int x = mid, y = mid + 1;
	int h = min(H[x], H[y]);
	while (x >= lo && y <= hi) {
		h = min(h, min(H[x], H[y]));
		cand = max(cand, h * (y - x + 1));
		if (x == lo) { y++; continue; }
		if (y == hi) { x--; continue; }

		if (H[x - 1] < H[y + 1]) y++;
		else x--;
	}
	return cand;
}