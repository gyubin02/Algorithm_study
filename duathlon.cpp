//UVa Online Judge 10385번 문제
//t = 총 트랙 길이, r = 달리기 트랙 길이, t-r = 자전거 트랙 길이
//n-1번째 선수가 1등하도록 r의 길이를 조정할 때, 1등과 2등의 완주 시간 차이가 최대가 되는 트랙 길이를 찾으시오
#include <iostream>
using namespace std;

int n, t;
double run[500], cycle[500];

//g(i, r) : i번 참가자의 완주 시간
//f(r) : 1등과 2등의 완주 시간 차이
double g(int i, double r) {
	return r / run[i] + (t - r) / cycle[i];
}

double f(double r) {
	double first = g(n - 1, r);
	double others = g(0, r);
	for (int i = 1; i < n - 1; i++)
		others = min(others, g(i, r));
	return others - first;
}

double search() { //f의 지역 극대점을 구한다
	double lo = 0, hi = t;
	for (int it = 0; it < 100; it++) {
		double x = (2 * lo + hi) / 3;
		double y = (lo + 2 * hi) / 3;
		if (f(x) <= f(y))
			lo = x;
		if (f(x) >= f(y))
			hi = y;
	}
	return (hi - lo) / 2;
}