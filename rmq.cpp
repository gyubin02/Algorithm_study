//range minimum query
#include <iostream>
#include <vector>
using namespace std;

const int MAX_E = 999999;

struct rmq {
	int n;
	vector<int> nodes;
	rmq(const vector<int>& arr) {
		n = arr.size();
		nodes.resize(4 * n);
		init(arr, 0, n - 1, 1);
	}

	int init(const vector<int>& arr, int lo, int hi, int node) {
		if (lo == hi) return nodes[node] = arr[lo];
		int mid = (lo + hi) / 2;
		int left = init(arr, lo, mid, node * 2);
		int right = init(arr, mid + 1, hi, node * 2 + 1);
		return nodes[node] = min(left, right);
	}

	int query(int fLeft, int fRight, int node, int lo, int hi) {
		//교집합이 없는 경우
		if (hi < fLeft || fRight < lo) return MAX_E;
		//[lo, hi]가 교집합인 경우
		if (fLeft <= lo && hi <= fRight) return nodes[node];
		//그 외 경우
		int mid = (lo + hi) / 2;
		return min(query(fLeft, fRight, node * 2, lo, mid), query(fLeft, fRight, node * 2 + 1, mid + 1, hi));
	}

	int query(int fLeft, int fRight){
		return query(fLeft, fRight, 1, 0, n - 1);
	}
};

int main() {
	vector<int> test = { 3,4,1,2,5 };
	rmq r(test);
	for (int i = 0; i < r.nodes.size(); i++)
		cout << r.nodes[i] << " ";
	while (true) {
		int a, b;
		cin >> a >> b;
		cout << r.query(a, b) << "\n";
	}
}
