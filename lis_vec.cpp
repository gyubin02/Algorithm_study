//LIS�� ���ҵ��� ���
#include <iostream>
#include <vector>
using namespace std;
int lis(int cur);
void reconstruct(int cur, vector<int>& seq);

const int MAX = 100;
int A[MAX];
int cache[MAX];
int choices[MAX];
int n;
vector<int> seq;

int main() {
	for (int i = 0; i < MAX; i++) cache[i] = -1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	int ret = 0;
	int start = -1;
	for (int i = 0; i < n; i++)
		if (ret < lis(i)) {
			start = i;
			ret = lis(i);
		}
	reconstruct(start, seq);
	for (int i = 0; i < seq.size(); i++) 
		cout << seq[i] << " ";
}

int lis(int cur) { //A[cur]�� �������� �ϴ� LIS�� ���̸� ��ȯ (�μ� ȿ�� : choices�� ������ ���� ����)
	//check memo
	int& ret = cache[cur];
	if (ret != -1) return ret;
	//step
	ret = 1;
	int bestNext = -1;
	for(int next=cur+1; next<n; next++)
		if (A[next] > A[cur]) {
			int cand = lis(next) + 1;
			if (ret < cand) { 
				bestNext = next;
				ret = cand;
			}
		}
	choices[cur] = bestNext;
	return ret;
}

void reconstruct(int cur, vector<int>& seq) { //A[cur]�� �������� �ϴ� LIS�� sequence�� sequ�� ����
	seq.push_back(A[cur]);
	if (choices[cur] != -1) reconstruct(choices[cur], seq);
}