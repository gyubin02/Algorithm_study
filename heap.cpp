//heap 구현
#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& heap, int x) { //heap에 원소 x를 넣는다.
	heap.push_back(x);
	int here = heap.size() - 1;
	while (here != 0 && heap[(here - 1) / 2] < heap[here]) {
		swap(heap[(here - 1) / 2], heap[here]);
		here = (here - 1) / 2;
	}
}

void pop(vector<int>& heap) { //heap에서 제일 큰 원소를 pop한다.
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = 2 * here + 1, right = 2 * here + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[left] > heap[next])
			next = left;
		if (right < heap.size() && heap[right] > heap[next])
			next = right;
		if (here == next) break;
		swap(heap[here], heap[next]);
		here = next;
	}
}

int main() {
	vector<int> heap;
	for (int i = 0; i < 10; i++)
		insert(heap, i);
	for (int i = 0; i < 5; i++) {
		cout << heap[0] << "\n";
		pop(heap);
	}
}