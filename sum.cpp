//0~N������ ���ڸ� K�� ���ؼ� N�� �Ǵ� ����� ��
/*
#include <iostream>
#include <vector>
using namespace std;
void DP(int N, int K, vector<vector<int>>& D);

int main() {
	int cases;
	cin >> cases;
	while (cases-- > 0) {
		int N, K;
		cin >> N >> K;
		vector<vector<int>> D(K+1, vector<int>(N+1, 0));
		for (int row = 0; row < K+1; row++) D[row][0] = 1;
		DP(N, K, D);
		cout << D[K][N] << "\n";
	}
}

void DP(int N, int K, vector<vector<int>>& D) {
	for (int row = 1; row < K+1; row++) {
		for (int col = 1; col < N+1; col++) {
			D[row][col] = D[row][col - 1] + D[row - 1][col];
		}
	}
}
*/