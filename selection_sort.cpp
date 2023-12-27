/*
    올바른 정렬은 완료된 후 두 가지 조건을 만족해야 합니다.
    1. 정렬 전후의 집합이 같아야 합니다. (집합은 순서를 고려하지 않습니다.)
    2. 정렬 후 집합은 오름차순 또는 내림차순입니다.

    Proof by Invariant (sort1)
    invariant : k번째 루프가 끝나면, 아래 두 가지 조건을 만족합니다. => P(k)
    1. (a가 공집합이 아니라면) a[0] < a[1] < ... < a[k-1]
    2. (a가 공집합이 아니라면) a[k-1] < a[x] if x > k-1
    k==n일 때 invariant를 만족하면 sort1은 올바른 정렬입니다. 귀납법으로 증명합니다. => P(n)
    base : P(0), 공집합임으로 vacuous true
    step : P(k-1) -> P(k), P(k-1)이 false라면 vacous true, P(k-1)이 true일 때만 확인합니다. k번째 루프에서 a[k],...,a[n-1] 중 최솟값을
    a[k]로 옮겼습니다. 즉 P(k-1)은 true입니다. step은 true
    base가 true이고 step이 true임으로 P(n)은 true

    Proof by induction (sort2)
    base : P(1), 정렬이 필요 없습니다. true
    step : P(k-1) -> P(k), P(k-1)이 false라면 vacous true, P(k-1)이 true일 때만 확인합니다.
    sort2(a+1, k-1) 호출이 끝난 후 a[1] < a[2] < ... < a[k-1] 이 만족한다면
    sort2(a, k) 호출이 끝난 후 a[0] < a[1] < a[2] < ... < a[k-1] 가 만족합니다. a[0] < a[x] if x > 0을 만족시킨 상태에서 sort2(a+1, k-1)을 호출하기
    때문입니다.
    step은 true
    base가 true이고 step이 true임으로 P(n)은 true

    시간 복잡도 : T(n) = n + T(n-1) = n + n - 1 + T(n-2) = n + ... + 2 + T(1) = O(n^2)

*/

#include <iostream>
using namespace std;

void sort1(int arr[], int n);
void sort2(int arr[], int n);

int main(void) {
    int arr[6] = { 2,4,5,6,3,1 };
    sort2(arr, 6);
    for (int a : arr) cout << a << " ";
}

void sort1(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int m = i;
        for (int j = i; j < n; j++) {
            if (arr[m] > arr[j]) m = j;
        }
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;
    }
    return;
}

void sort2(int arr[], int n) {
    if (n == 1) return;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (arr[m] > arr[i]) m = i;
    }
    int temp = arr[0];
    arr[0] = arr[m];
    arr[m] = temp;
    sort2(arr + 1, n - 1);
    return;
}
