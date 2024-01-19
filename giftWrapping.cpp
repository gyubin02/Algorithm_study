//볼록 껍질 구하기 (선물 포장 알고리즘)
#include <iostream>
#include <vector>
using namespace std;

struct vector2 {
	double x, y;
	explicit vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}
	bool operator ==(const vector2& rhs) {
		return x == rhs.x && y == rhs.y;
	}
	bool operator <(const vector2& rhs) {
		return (x != rhs.x) ? x < rhs.x : y < rhs.y;
	}
	vector2 operator -(const vector2& rhs) {
		return vector2(x - rhs.x, y - rhs.y);
	}
	double norm() const {
		return sqrt(x * x + y * y);
	}
	double cross(const vector2& rhs) {
		return x * rhs.y - y * rhs.x;
	}
};

double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

double ccw(vector2 a, vector2 b, vector2 c) {
	return ccw(b - a, c - a);
}

vector<vector2> wrap(vector<vector2>& poly) { //gift wrapping 알고리즘
	vector<vector2> convex_hull;
	vector2 last = *min_element(poly.begin(), poly.end());
	convex_hull.push_back(last);
	while (true) {
		last = convex_hull.back();
		vector2 next = poly[0];
		for (int i = 1; i < poly.size(); i++) {
			double cc = ccw(last, next, poly[i]);
			double nn = (next - last).norm();
			double pp = (poly[i] - last).norm();
			if (cc > 0 || (cc == 0 && pp > nn))
				next = poly[i];
		}
		if (next == convex_hull.front())
			break;
		convex_hull.push_back(next);
	}
	return convex_hull;
}