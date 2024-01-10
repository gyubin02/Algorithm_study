//여행하는 외판원
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_N = 30;
const int CACHED_DEPTH = 5;
const double INF = 99999999;
double dist[MAX_N][MAX_N], minEdge[MAX_N];
double best;
int n;
vector<int> nearest[MAX_N];
vector<pair<double, pair<int, int>>> edges;
int node[MAX_N];
int parent[MAX_N];
map<int, double> cache[MAX_N][CACHED_DEPTH];

int find(int here) {
	int& ret = parent[here];
	if (ret == here)
		return ret;
	return ret = find(ret);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
	return true;
}

double func(vector<int>& path, vector<bool>& visited, double currentLength) {
	//pruning
	if (path.size() + CACHED_DEPTH >= n) {
		best = min(best, dp(path.back(), change(visited)));
		return best;
	}
	if (currentLength >= best) return;
	if (currentLength + heuristic_1(visited) >= best) return;
	if (currentLength + heuristic_2(path.back(), visited) >= best) return;
	if (heuristic_3(path)) return;
	if (heuristic_4(path)) return;
	//base
	if (path.size() == n)
		return best = currentLength + dist[path.back()][0];
	//step
	for (int i = 0; i < nearest[path.back()].size(); i++) {
		int node = nearest[path.back()][i];
		if (visited[node]) continue;
		path.push_back(node);
		visited[node] = true;
		best = min(best, func(path, visited, currentLength + dist[path.back()][node]));
		path.pop_back();
		visited[node] = false;
	}
	return best;
}

double dp(int here, int visited) {
	//base
	if (visited == (1 << n) - 1)
		return dist[here][0];
	//check memo
	int remaining = count(visited);
	double& ret = cache[here][remaining][visited];
	if (ret > 0) return ret;
	//step
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		int next_visited = visited | (1 << i);
		ret = min(ret, dist[here][i] + dp(i, next_visited));
	}
	return ret;
}

int count(int num) { //return the number of 0 in num 
	//base
	if (num < 10)
		return 0;
	//step
	if (num % 10)
		return count(num / 10);
	return 1 + count(num / 10);
}

int change(vector<bool>& visited) {
	int ret = 0;
	for (int i = n-1; i >= 0; i--) {
		if (visited[i])
			ret++;
		ret = ret << 1;
	}
	return ret;
}

double solve() {
	//calculate minEdge of each node
	for (int i = 0; i < n; i++) {
		minEdge[i] = INF;
		for (int j = 0; j < n; j++)
			if (i != j)
				minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	//sort each node in ascending order based on proximity
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> order;
		for (int j = 0; j < n; j++)
			if (i != j)
				order.push_back(make_pair(dist[i][j], j));
		sort(order.begin(), order.end());
		for (int j = 0; j < order.size(); j++)
			nearest[i].push_back(order[j].second);
	}
	//sort all edges in ascending order based on weight
	edges.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			edges.push_back(make_pair(dist[i][j], make_pair(i, j)));
	sort(edges.begin(), edges.end());
	//
	best = INF;
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	func(path, visited, 0);
	return best;
}

//heuristic function
double heuristic_1(vector<bool>& visited) {
	double ret = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}

double heuristic_2(int here, vector<bool>& visited) { //return length of MST using kruskal algorithm
	int ret = 0, count = 0;
	for (int edge = 0; edge < edges.size(); edge++) {
		if (count == n - 1) break; //exit the loop when the number of selected edges is equal to the number of nodes minus 1
		int node_1 = edges[edge].second.first;
		int node_2 = edges[edge].second.second;
		if (node_1 != 0 && node_1 != here && visited[node_1]) continue;
		if (node_2 != 0 && node_2 != here && visited[node_2]) continue;
		if (!merge(node_1, node_2)) continue;
		ret += dist[node_1][node_2];
		count++;
	}
	return ret;
}

bool heuristic_3(const vector<int>& path) { //return true when swapping two nodes among last four nodes results in shorter path
	if (path.size() < 4) return false;
	int n_1 = path[path.size() - 4];
	int n_2 = path[path.size() - 3];
	int n_3 = path[path.size() - 2];
	int n_4 = path[path.size() - 1];
	return dist[n_1][n_2] + dist[n_3][n_4] > dist[n_1][n_3] + dist[n_2][n_4];
}

bool heuristic_4(const vector<int>& path) { //return true when reversing the subpath excluding start node and current node results in shorter path
	if (path.size() < 4) return false;
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i < path.size() - 3; i++) {
		int a = path[i];
		int p = path[i + 1];
		if (dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q])
			return true;
	}
	return false;
}