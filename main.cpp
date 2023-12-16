/*
    �ùٸ� ������ �Ϸ�� �� �� ���� ������ �����ؾ� �մϴ�.
    1. ���� ������ ������ ���ƾ� �մϴ�. (������ ������ ������� �ʽ��ϴ�.)
    2. ���� �� ������ �������� �Ǵ� ���������Դϴ�.

    Proof by Invariant (sort1)
    invariant : k��° ������ ������, �Ʒ� �� ���� ������ �����մϴ�. => P(k)
    1. (a�� �������� �ƴ϶��) a[0] < a[1] < ... < a[k-1]
    2. (a�� �������� �ƴ϶��) a[k-1] < a[x] if x > k-1
    k==n�� �� invariant�� �����ϸ� sort1�� �ùٸ� �����Դϴ�. �ͳ������� �����մϴ�. => P(n)
    base : P(0), ������������ vacuous true
    step : P(k-1) -> P(k), P(k-1)�� false��� vacous true, P(k-1)�� true�� ���� Ȯ���մϴ�. k��° �������� a[k],...,a[n-1] �� �ּڰ���
    a[k]�� �Ű���ϴ�. �� P(k-1)�� true�Դϴ�. step�� true
    base�� true�̰� step�� true������ P(n)�� true

    Proof by induction (sort2)
    base : P(1), ������ �ʿ� �����ϴ�. true
    step : P(k-1) -> P(k), P(k-1)�� false��� vacous true, P(k-1)�� true�� ���� Ȯ���մϴ�.
    sort2(a+1, k-1) ȣ���� ���� �� a[1] < a[2] < ... < a[k-1] �� �����Ѵٸ�
    sort2(a, k) ȣ���� ���� �� a[0] < a[1] < a[2] < ... < a[k-1] �� �����մϴ�. a[0] < a[x] if x > 0�� ������Ų ���¿��� sort2(a+1, k-1)�� ȣ���ϱ�
    �����Դϴ�.
    step�� true
    base�� true�̰� step�� true������ P(n)�� true

    �ð� ���⵵ : T(n) = n + T(n-1) = n + n - 1 + T(n-2) = n + ... + 2 + T(1) = O(n^2)

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