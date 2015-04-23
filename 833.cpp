#include <bits/stdc++.h>
using namespace std; 
class point {
public :
	int x, y;
//	double x, y;

	point() {}
	point(int i, int j) { x = i; y = j; }
//	point(double i, double j) { x = i, y = j; }

//	double norm = sqrt(x*x+y*y); 

	point operator + (const point &rhs)
	{
		point tmp;
		tmp.x = x+rhs.x;
		tmp.y = y+rhs.y;

		return tmp;
	}

	point operator - (const point &rhs)
	{
		point tmp;
		tmp.x = x-rhs.x;
		tmp.y = y-rhs.y;

		return tmp;
	}

	int operator * (const point &rhs) { return x*rhs.x + y*rhs.y; } //dot product
	int operator ^ (const point &rhs) { return x*rhs.y - y*rhs.x; } //cross product
};

struct line {
	point a, b;

	line() {}
	line(point i, point j) { a = i; b = j; }

//	double norm = sqrt(a.x*b.x + a.y*b.y);
};


int direction(line s, point c) //This wil return 0 if a,b,c is co-liniear, return + if C is counterclockwise to AB, - if C is clockwise to AB
{
	return (s.b-s.a)^(c-s.a);
}

bool onSegment(line l, point p)
{
	return min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x) && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
}

bool segmentIntersect(point a, point b, point c, point d) //return true if two segments intersect
{
	//two lines are AB and CD
	/*
	int d1 = direction(c, d, a); //direction of A, with respect to line CD;
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);
	*/

	int d1 = direction(line(c, d), a);
	int d2 = direction(line(c, d), b);
	int d3 = direction(line(a, b), c);
	int d4 = direction(line(a, b), d);

	if(d1*d2 < 0 && d3*d4 < 0) return 1; //if they intersect;
	if(d1 == 0 && onSegment(line(c, d), a)) return 1; 
	if(d2 == 0 && onSegment(line(c, d), b)) return 1;
	if(d3 == 0 && onSegment(line(a, b), c)) return 1;
	if(d4 == 0 && onSegment(line(a, b), d)) return 1;

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

double distTwoPoints(point a, point b)
{
	return sqrt(a.x*b.x+a.y*b.y);
}

double linePointDist(line l, point p, bool isSegment)
{
	double dist = (double) abs((l.b-l.a)^(p-l.a))/distTwoPoints(l.a, l.b);

	if(isSegment) {
		point v = l.b-l.a;
		point w = p-l.a;

		int c1 = v*w;
		if(c1 <= 0) return distTwoPoints(l.a, p);

		int c2 = v*v;
		if(c2 <= c1) return distTwoPoints(l.b, p);
	}
	return dist;
}

double area2Dpolygon(int n, point a[])
{
	double area = 0;

	for(int i = 1, j = 0, k = 2; i < n; ++i, ++j, ++k) area += a[i].x*(a[k].y-a[j].y);
	area += a[0].x*(a[1].y-a[n-1].y);

	return area/2.0;
}

//end of geo templete

line a[1000000];

int main()
{
	int t, n, m;
	point p;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &a[i].a.x, &a[i].a.y, &a[i].b.x, &a[i].b.y);
			if(a[i].a.x > a[i].b.x) swap(a[i].a, a[i].b); 
		}

		scanf("%d", &m);

		while(m--) {
			scanf("%d%d", &p.x, &p.y);

			while(1) {
				bool f = 1;
				double mn = 10000000000.0;
				int nearestLine = -1;
				for(int i = 0; i < n; ++i) {
					if(a[i].a.x < p.x && p.x < a[i].b.x && direction(a[i], p) > 0) {
						double tmp = linePointDist(a[i], p, 0);
						if(tmp < mn) {
							mn = tmp;
							nearestLine = i;
						}
					}
				}
				if(nearestLine == -1) break;
				p = a[nearestLine].a.y<a[nearestLine].b.y?a[nearestLine].a:a[nearestLine].b;

			}
			printf("%d\n", p.x);
		}
		if(t) printf("\n");
	}

	return 0;
}
