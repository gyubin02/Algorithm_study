/*Binary Search ±¸Çö*/
#include <iostream>
int BS(int low, int high, int x);

int A[10] = { 1,3,5,7,8,9,11,14,16,17 };

int main() {
	std::cout << BS(0, 9, 14);
}

int BS(int low, int high, int x) {
	//base
	if (low == high){
		if (A[low] == x) return low;
		else return -1;
	}
	//step
	int mid = (low + high) / 2;
	if (A[mid] == x) return mid;
	if (A[mid] < x) return BS(mid + 1, high, x);
	if (A[mid] > x) return BS(low, mid - 1, x);
}
