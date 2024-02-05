//tri ±¸Çö
#include <iostream>
using namespace std;


const int Alphabet = 26;
int toNumber(char ch) {
	return ch - 'A';
}
struct Tri {
	Tri* children[Alphabet];
	bool terminal;
	Tri():terminal(false){
		for (int i = 0; i < Alphabet; i++)
			children[i] = 0;
	}
	~Tri() {
		for (int i = 0; i < Alphabet; i++)
			if (children[i])
				delete(children[i]);
	}
	void insert(const char* key) {
		if (*key == 0) {
			terminal = true;
			return;
		}
		int next = toNumber(*key);
		if (children[next] != NULL)
			children[next] = new Tri();
		children[next]->insert(key + 1);
	}
	Tri* find(const char* key) {
		if (*key == 0)
			return this;
		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}
};