//ccw�� ���� ���� ����
#include <iostream>
using namespace std;

struct vector2 {
	double x, y;
	explicit vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}
	bool operator <(const vector2& rhs) {
		return (x != rhs.x) ? x < rhs.x : y < rhs.y;
	}
	vector2 operator -(const vector2& rhs) {
		return vector2(x - rhs.x, y - rhs.y);
	}
	double cross(const vector2& rhs) {
		return x * rhs.y - y * rhs.x;
	}
};

double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

double ccw(vector2 a, vector2 b, vector2 c) { //����� a-b-c�� b���� ��ȸ��
	return ccw(b - a, c - a);
}

bool isIntersect(vector2 a, vector2 b, vector2 c, vector2 d) { //���� ab�� cd�� �����ϴ��� ���θ� ��ȯ
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	double x = ccw(a, b, c) * ccw(a, b, d);
	double y = ccw(c, d, a) * ccw(c, d, b);

	if (x == 0 && y == 0) {
		return !(b < c || d < a);
	}

	return x <= 0 && y <= 0;
}