//문제 ID : FAMILYTREE
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000;

struct Node {
	int label;
	vector<Node*> children;
	Node* parent;
	Node(int label, Node* parent) :label(label), parent(parent) {}
};

vector<int> depth(MAX_N); //depth[i] = i번 노드의 깊이

void getDepth(Node* root, int dep) {
	depth[root->label] = dep;
	for (int i = 0; i < root->children.size(); i++)
		getDepth(root->children[i], dep + 1);
}

vector<int> trip; //trip[i] = i번째로 방문한 노드의 번호
vector<int> locInTrip(MAX_N); //locInTrip[i] = i번 노드의 trip에서 위치
void preOrderTravel(Node* root) {
	locInTrip[root->label] = trip.size();
	trip.push_back(root->label);
	for (int i = 0; i < root->children.size(); i++) {
		preOrderTravel(root->children[i]);
		trip.push_back(root->label);
	}
}

struct rmdq {
	int n;
	vector<int> minDepth;
	rmdq(vector<int>& trip) {
		n = trip.size();
		minDepth.resize(4 * n);
		init(trip, 0, n - 1, 1);
	}

	int init(vector<int>& trip, int lo, int hi, int node) {
		if (lo == hi) return minDepth[node] = depth[trip[lo]];
		int mid = (lo + hi) / 2;
		int left = init(trip, lo, mid, node * 2);
		int right = init(trip, mid + 1, hi, node * 2 + 1);
		return minDepth[node] = min(left, right);
	}

	int query(int lo, int hi, int node, int fLeft, int fRight) {
		if (hi < fLeft || fRight < lo) return 999999999;
		if (fLeft <= lo && hi <= fRight) return minDepth[node];
		int mid = (lo + hi) / 2;
		return min(query(lo, mid, node * 2, fLeft, fRight), query(mid + 1, hi, node * 2 + 1, fLeft, fRight));
	}

	int query(int fLeft, int fRight) {
		if (fLeft > fRight) swap(fLeft, fRight);
		return query(0, n - 1, 1, fLeft, fRight);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C;
	cin >> C;
	while (C-- > 0) {
		int N, Q;
		cin >> N >> Q;
		vector<Node*> nodes;
		for (int i = 0; i <= N - 1; i++)
			nodes.push_back(new Node(i, NULL));
		for (int i = 1; i <= N - 1; i++) {
			int parent;
			cin >> parent;
			nodes[i]->parent = nodes[parent];
			nodes[parent]->children.push_back(nodes[i]);
		}
		getDepth(nodes[0], 0);
		preOrderTravel(nodes[0]);
		rmdq r(trip);
		for (int i = 0; i < Q; i++) {
			int a, b;
			cin >> a >> b;
			int c = locInTrip[a];
			int d = locInTrip[b];
			int lca = r.query(c, d);
			cout << depth[a] + depth[b] - 2 * lca << "\n";
		}
		cout << "\n";
	}
	
}