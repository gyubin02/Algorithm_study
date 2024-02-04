//∆Ê¿® ∆Æ∏Æ
#include <iostream>
#include <vector>
using namespace std;

struct Fenwick {
	int n;
	vector<int> tree;
	Fenwick(int _n) :n(_n+1) {
		tree.resize(n);
	}

	int sum(int pos) {
		pos++;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, int val){
		pos++;
		while (pos <= n) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main() {
	int C;
	cin >> C;
	while (C-- > 0) {
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		Fenwick f(1000000);
		int ret = 0;
		for (int i = 0; i < N; i++) {
			ret += f.sum(999999) - f.sum(arr[i]);
			f.add(arr[i], 1);
		}
		cout << ret << "\n";
	}
}