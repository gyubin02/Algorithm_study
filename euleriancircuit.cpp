//오일러 서킷 구현
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> res;
void getEulerCircuit(int here) {
	for (int there = 0; there < adj[here].size(); there++)
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there);
		}
	res.push_back(here);
}