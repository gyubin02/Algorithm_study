//Ʈ�� ���� (���� ���� �����˻�Ʈ��)
#include <iostream>
using namespace std;

typedef int keyType;
struct Node {
	keyType key;
	int priority, size;
	Node *left, *right;
	Node(keyType& _key) :key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* node) { left = node; calcSize(); }
	void setRight(Node* node) { right = node; calcSize(); }
	void calcSize() { size = left->size + 1 + right->size; }
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, keyType key) {
	//base
	if (root == NULL) return NodePair(NULL, NULL);
	//step
	if (root->key < key) {
		NodePair r = split(root->right, key);
		root->setRight(r.first);
		return NodePair(root, r.second);
	}
	NodePair l = split(root->left, key);
	root->setLeft(l.second);
	return NodePair(l.first, root);
}

Node* insert(Node* root, Node* node) {
	//base
	if (root == NULL) return node;
	//step
	if (root->priority > node->priority) {
		if (root->key > node->key)
			root->setLeft(insert(root->left, node));
		else
			root->setRight(insert(root->right, node));
		return root;
	}
	else {
		NodePair sub = split(root, node->key);
		node->setLeft(sub.first);
		node->setRight(sub.second);
		return node;
	}
}

Node* merge(Node* L, Node* R) { //L->key < R->key ��� ����
	//base
	if (L == NULL) return R;
	if (R == NULL) return L;
	//step
	if (L->priority > R->priority) {
		L->setRight(merge(L->right, R));
		return L;
	}
	R->setLeft(merge(L, R->left));
	return R;
}

Node* erase(Node* root, keyType key) { //root�� ��Ʈ�� �ϴ� Ʈ������ key�� ���� ��� Ʈ���� ��Ʈ�� ��ȯ�Ѵ�.
	if (root == NULL) return NULL;
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (root->key < key)
		root->setRight(erase(root->right, key));
	else
		root->setLeft(erase(root->left, key));
	return root;
}

Node* findK(Node* root, int k) { //root�� ��Ʈ�� �ϴ� Ʈ���� ������ key�� ������������ �������� �� k ��° ��带 ��ȯ�Ѵ�.
	int L = 0;
	if (root->left != NULL)
		L = root->left->size;
	if (k <= L) return findK(root->left, k);
	if (k == L + 1) return root;
	return findK(root->right, k - L - 1);
}

int countLessThan(Node* root, int x) { //root�� ��Ʈ�� �ϴ� Ʈ������ key ���� x���� ���� ����� ������ ��ȯ�Ѵ�.
	if (root == NULL) return 0;
	if (root->key >= x)
		return countLessThan(root->left, x);
	int a = root->left ? root->left->size : 0;
	return a + 1 + countLessThan(root->right, x);
}

Node* find(Node* root, int x) { //root�� ��Ʈ�� �ϴ� Ʈ������ key ���� x�� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return NULL;
	if (root->key == x) return root;
	if (root->key < x) return find(root->right, x);
	return find(root->left, x);
}