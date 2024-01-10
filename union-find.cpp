//union-find 구현
#include <iostream>

const int MAX_N = 30;
int parent[MAX_N];
int node[MAX_N];

int find(int here) {
	if (parent[here] == here) 
		return here;
	return parent[here] = find(parent[here]);
}

bool merge(int a, int b) { //cyle이 발생하면 false
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