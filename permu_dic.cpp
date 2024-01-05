//순열의 사전 순 번호 출력하기
#include <iostream>
#include <vector>
using namespace std;
int permu_dict(vector<int>& permu);
int fact(int n);

int factorial[11];

int main() {
	for (int i = 0; i < 11; i++) 
		factorial[i] = -1;
	vector<int> permu = { 4,2,1,3,5,6,7,8,9,10 };
	cout << permu_dict(permu);
}

int permu_dict(vector<int>& permu) { //permu의 사전 순 번호를 반환하는 함수
	int ret = 0;
	for (int i = 0; i < permu.size(); i++) {
		int pack = 0;
		for (int j = i + 1; j < permu.size(); j++)
			if (permu[i] > permu[j])
				pack++;
		ret += fact(permu.size() - (i + 1)) * pack;
	}
	return ret + 1;
}

int fact(int n) { //n!을 반환
	//base
	if (n == 0) return 1;
	//check memo
	int& ret = factorial[n];
	if (ret != -1) return ret;
	//step
	return ret = n * fact(n - 1);
}