#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
	point() {}
	point(int i, int j) { x = i; y = j; }
};

int vectorCross(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

int direction(point a, point b, point c)
{
	return vectorCross(point (c.x-a.x, c.y-a.y), point (b.x-a.x, b.y-a.y));
}

bool onSegment(point a, point b, point c)
{
	return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool segmentIntersect(point a, point b, point c, point d)
{
	int d1 = direction(c, d, a);
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) return 1;
	if(d1 == 0 && onSegment(c, d, a)) return 1;
	if(d2 == 0 && onSegment(c, d, b)) return 1;
	if(d3 == 0 && onSegment(a, b, c)) return 1;
	if(d4 == 0 && onSegment(a, b, d)) return 1;

	return 0;
}


int main()
{
	int t;

	scanf("%d", &t);

	point a, b, p, q;

	while(t--) {
		scanf("%d%d%d%d%d%d%d%d", &p.x, &p.y, &q.x, &q.y, &a.x, &a.y, &b.x, &b.y);

		if(a.x > b.x) swap(a.x, b.x);
		if(a.y < b.y) swap(a.y, b.y);

		point c(a.x, b.y);
		point d(b.x, a.y);

		if(segmentIntersect(p, q, a, c) || segmentIntersect(p, q, a, d) || segmentIntersect(p, q, b, c) || segmentIntersect(p, q, b, d) || onSegment(a, b, p) || onSegment(a, b, q)) printf("T\n");
		else printf("F\n");
	}

	return 0;
}
