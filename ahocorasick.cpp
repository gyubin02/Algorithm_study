//아호-코라식 (다중 문자열 검색)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Alphabet = 26;
int toNumber(const char ch) {
	return ch - 'A';
}
struct Tri {
	int terminal;
	Tri* children[Alphabet];
	Tri* fail;
	vector<int> output;
	Tri():terminal(-1), fail(NULL){
		for (int i = 0; i < Alphabet; i++)
			children[i] = 0;
	}
	~Tri() {
		for (int i = 0; i < Alphabet; i++)
			if (children[i])
				delete(children[i]);
	}
	void insert(const char* key, int id) {
		if (*key == 0) {
			terminal = id;
			return;
		}
		int next = toNumber(*key);
		if (children[next] == NULL)
			children[next] = new Tri();
		children[next]->insert(key + 1, id);
	}
	Tri* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}
};

void computeFail(Tri* root) {
	queue<Tri*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Tri* here = q.front();
		q.pop();
		for (int i = 0; i < Alphabet; i++) {
			Tri* child = here->children[i];
			if (!child) continue;
			Tri* t = here->fail;
			while (t != root && t->children[i] == NULL)
				t = t->fail;
			if (t->children[i]) t = t->children[i];
			child->fail = t;

			child->output = child->fail->output;
			if (child->terminal != -1) 
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

vector<pair<int, int>> ahoCorasick(const string& str, Tri* root) {
	vector<pair<int, int>> ret;
	Tri* state = root;
	for (int i = 0; i < str.size(); i++) {
		int num = toNumber(str[i]);
		while (state != root && state->children[num] == NULL)
			state = state->fail;
		if (state->children[num])
			state = state->children[num];
		for (int j = 0; j < state->output.size(); j++)
			ret.push_back(make_pair(i, state->output[j]));
	}
	return ret;
}