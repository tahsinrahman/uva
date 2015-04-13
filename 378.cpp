#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
	point() {}
	point(int i, int j) { x = i; y = j; }
};

int crossProduct(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

int direction(point a, point b, point c)
{
	return crossProduct(point (c.x-a.x, c.y-a.y), point (b.x-a.x, b.y-a.y));
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
		if(direction(a, b, c) == 0 && direction(a, b, d) == 0) printf("LINE\n");
		else printf("NONE\n");
	}
	else {
		double x = (double) (b1*c2-b2*c1)/det;
		double y = (double) (a2*c1-a1*c2)/det;

		printf("POINT %.2lf %.2lf\n", x, y);
	}
}




int main()
{
	int t;
	scanf("%d", &t);

	point a[4];

	printf("INTERSECTING LINES OUTPUT\n");
	while(t--) {
		for(int i = 0; i < 4; ++i) scanf("%d%d", &a[i].x, &a[i].y);

		lineIntersect(a[0], a[1], a[2], a[3]);
	}
	printf("END OF OUTPUT\n");

	return 0;
}
