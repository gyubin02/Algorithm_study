//�� ��ȣ ������ ��� (���� Ž�� �̿�)
#include <iostream>
using namespace std;
void generate(int n, int m, string s);

int n, m, skip;

int main() {
	int k;
	cin >> n >> m >> k;
	skip = k - 1;
	string s = "";
	generate(n, m, s);
}

void generate(int n, int m, string s) { //�� ��� �ϴ� ������ �� : n��,  �� ��� �ϴ� ������ �� : m��
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if(skip == 0) cout << s << "\n";
		skip--;
		return;
	}
	if (n > 0) generate(n - 1, m, s + '-');
	if (m > 0) generate(n, m - 1, s + 'o');
}