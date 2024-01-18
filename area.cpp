//���� �ٰ��� ���� ���ϱ� && ����/�ܺ� �Ǻ�
#include <iostream>
#include <vector>
using namespace std;

struct vector2 {
	double x, y;
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	vector2 operator +(const vector2& rhs) {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator -(const vector2& rhs) {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator *(double rhs) {
		return vector2(x * rhs, y * rhs);
	}
	double cross(const vector2& rhs) {
		return x * rhs.y - y * rhs.x;
	}
};

int n;
vector2 poly[20]; //�ٰ����� �̷�� ������ �ð� ���� �Ǵ� �ݽð� �������� �־����ٰ� �����Ѵ�

double area() { //���� �ٰ����� ������ ��ȯ
	double ret = 0;
	for (int k = 0; k <= n - 1; k++)
		ret += poly[k].cross(poly[(k + 1) % n]);
	ret /= 2;
	return fabs(ret);
}

bool inInside(vector2& point) { //point�� ���� �ٰ����� ���ο� �ִٸ� ���� ��ȯ
	int count = 0;
	for (int k = 0; k <= n - 1; k++)
		if ((point.y > poly[k].y) != (point.y < poly[(k + 1) % n].y)) {
			double c = (point.y - poly[k].y) * (poly[(k + 1) % n].x - poly[k].x) / (poly[(k + 1) % n].y - poly[k].y) + poly[k].x;
			if (c > point.x) count++;
		}
	return count % 2 > 0;
}