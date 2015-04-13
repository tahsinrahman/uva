#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
	point() {}
	point(double i, double j) { x = i; y = j; }
};

double crossProduct(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

double direction(point a, point b, point c)
{
	return crossProduct(point (c.x-a.x, c.y-a.y), point (b.x-a.x, b.y-a.y));
}

bool onSegment(point a, point b, point c)
{
	return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool segmentIntersect(point a, point b, point c, point d)
{
	double d1 = direction(c, d, a);
	double d2 = direction(c, d, b);
	double d3 = direction(a, b, c);
	double d4 = direction(a, b, d);

	if(d1*d2 < 0 && d3*d4 < 0) return 1;
//	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) return 1;
//	if(d1 == 0 && onSegment(c, d, a)) return 1;
//	if(d2 == 0 && onSegment(c, d, b)) return 1;
//	if(d3 == 0 && onSegment(a, b, c)) return 1;
//	if(d4 == 0 && onSegment(a, b, d)) return 1;

	return 0;
}

void lineIntersect(point a, point b, point c, point d)
{
	int a1 = b.y-a.y;
	int b1 = a.x-b.x;
	int c1 = b.x*a.y-a.x*b.y;

	int a2 = d.y-c.y;
	int b2 = c.x-d.x;
	int c2 = d.x*c.y-c.x*d.y;

	int det = (a1*b2-a2*b1);

	if(det == 0) {
//		if(direction(a, b, c) == 0 && direction(a, b, d) == 0) printf("LINE\n");
//		else printf("NONE\n");
	}
	else {
		double x = (double) (b1*c2-b2*c1)/det;
		double y = (double) (a2*c1-a1*c2)/det;

//		printf("POINT %.2lf %.2lf\n", x, y);
	}
}

int main()
{
	int n;

	while(scanf("%d", &n) && n) {
		point a[n][2];
		for(int i = 0; i < n; ++i) for(int j = 0; j < 2; ++j) scanf("%lf%lf", &a[i][j].x, &a[i][j].y);

		vector <int> ans;

		for(int i = 0; i < n; ++i) {
			bool f = 1;
			for(int j = i+1; j < n; ++j) {
				if(segmentIntersect(a[i][0], a[i][1], a[j][0], a[j][1])) {
					f = 0;
					break;
				}
			}
			if(f) ans.push_back(i+1);
		}

		printf("Top sticks: ");
		printf("%d", ans[0]);
		for(int i = 1, s = ans.size(); i < s; ++i) printf(", %d", ans[i]);
		printf(".\n");
	}

	return 0;
}
