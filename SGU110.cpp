#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const double eps = 1e-10;
struct Point {
	double x, y, z;
	Point(double x, double y, double z):
		x(x), y(y), z(z) {}
	Point(){}
	Point operator+(const Point t) const{
		return Point(x+t.x, y+t.y, z+t.z);
	}
	Point operator-(const Point t) const {
		return Point(x-t.x, y-t.y, z-t.z);
	}
	Point operator*(const double t) const {
		return Point(x*t, y*t, z*t);
	}
	double operator*(const Point t) const {
		return x*t.x+y*t.y+z*t.z;
	}
	void in() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	void out() {
		printf("%lf %lf %lf~~~~\n", x, y, z);
	}
}o[55], base, dir;
int n;
vector <int> ans;
double r[55];
int work() {
	int i, j;
	double tmp = 2*1e9;
	int pos = -1;
	double e, f, g, dlt, t;
	for(i = 0; i < n; i++) {
		e = dir*dir;
		f = (base-o[i])*dir*2;
		g = (base-o[i])*(base-o[i])-r[i]*r[i];
		dlt = f*f-4*e*g;
		if(dlt < -eps) continue;
		dlt = sqrt(dlt);
		t = (-f-dlt)/(e*2);
		if(t < eps) continue;
		if(tmp > t+eps) tmp = t, pos = i;
	}
	if(pos == -1) return -1;
	base = dir*tmp+base;
	Point v = base-o[pos];
	dir = dir - v*(v*dir*2/(v*v));
	return pos+1;
}
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		o[i].in();
		scanf("%lf", &r[i]);
	}
	base.in(); dir.in();
	dir = dir-base;
	for(i = 0; i < 11; i++) {
		int t = work();
		if(t == -1) break;
		ans.push_back(t);
	}
	if(ans.size() > 10) {
		for(i = 0; i < 10; i++) 
			printf("%d ", ans[i]);
		puts("etc.");
	}else {
		for(i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}