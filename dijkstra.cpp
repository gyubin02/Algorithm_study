//다익스트라 구현
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N;
vector<vector<pair<int, int>>> adj; //(가중치, 정점 번호)
vector<int> dijkstra(int start) {
	vector<int> dist(N, 9999);
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	dist[start] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int here = q.top().second;
		q.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int weight = adj[here][i].first;
			int there = adj[here][i].second;
			if (cost + weight > dist[there]) continue;
			q.push(make_pair(-(cost + weight), there));
			dist[there] = cost + weight;
		}
	}
}