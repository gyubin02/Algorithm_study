//merge sort ±¸Çö
#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int>& A, int left, int right) {
	//base
	if (left == right) return;
	//step
	vector<int> tmp(right - left + 1);
	int mid = (left + right) / 2;
	merge_sort(A, left, mid);
	merge_sort(A, mid + 1, right);
	int tmpIndex = 0, leftIndex = left, rightIndex = mid + 1;
	while (leftIndex <= mid || rightIndex <= right){
		if (leftIndex <= mid && (rightIndex > right || A[leftIndex] <= A[rightIndex]))
			tmp[tmpIndex++] = A[leftIndex++];
		else
			tmp[tmpIndex++] = A[rightIndex++];
	}
	for (int i = 0; i < tmp.size(); i++)
		A[left + i] = tmp[i];
}

int main() {
	vector<int> A = { 3, 5, 7, 1, 4 };
	merge_sort(A, 0, A.size() - 1);
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}