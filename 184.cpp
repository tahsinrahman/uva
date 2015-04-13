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
//	long long operator * (const point &rhs) { return (long long) x*rhs.x + (long long) y*rhs.y; } //dot product
//	long long operator ^ (const point &rhs) { return (long long) x*rhs.y - (long long) y*rhs.x; } //cross product
};

struct line {
	//a line with two endpoints a and b
	point a, b;

	line(point i, point j) { a = i; b = j; }
//	double norm = sqrt(a.x*b.x + a.y*b.y);
};


int direction(point a, point b, point c) //This wil return 0 if a,b,c is co-liniear, return + if C is counterclockwise to AB, - if C is clockwise to AB
{
	return (b-a)^(c-a);
}

int direction(line s, point c) //This wil return 0 if a,b,c is co-liniear, return + if C is counterclockwise to AB, - if C is clockwise to AB
{
	return (s.b-s.a)^(c-s.a);
}

bool onSegment(point a, point b, point c) //check if point C is on the line AB or not
{
	return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool segmentIntersect(point a, point b, point c, point d) //return true if two segments intersect
{
	//two lines are AB and CD
	int d1 = direction(c, d, a); //direction of A, with respect to line CD;
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);
	/*
	long long d1 = direction(c, d, a); //direction of A, with respect to line CD;
	long long d2 = direction(c, d, b);
	long long d3 = direction(a, b, c);
	long long d4 = direction(a, b, d);
	*/
	
	if(d1*d2 < 0 && d3*d4 < 0) return 1; //if they intersect;
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

double linePointDist(point a, point b, point c, bool isSegment)
{
	double dist = (double) abs((b-a)^(c-a))/distTwoPoints(a, b);

	if(isSegment) {
		point v = b-a;
		point w = c-a;

		int c1 = v*w;
		if(c1 <= 0) return distTwoPoints(a, c);

		int c2 = v*v;
		if(c2 <= c1) return distTwoPoints(b, c);
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

point a[1000];
vector <line> taken;

bool cmp(point a, point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool check(point p, point q)
{
	for(int i = 0; i < taken.size(); ++i) if(direction(taken[i], p) == 0 && direction(taken[i], q) == 0) return 1;
	return 0;
}

int main()
{
	while(scanf("%d%d", &a[0].x, &a[0].y)) {
		if(!a[0].x && !a[0].y) break;
		int n = 1;
		while(scanf("%d%d", &a[n].x, &a[n].y)) { if(!a[n].x && !a[n].y) break; ++n; }

		sort(a, a+n, cmp);

		bool f;
		vector <int> lines[n][n];
		taken.clear();

		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				if(check(a[i], a[j])) continue;
				f = 0;
				for(int k = j+1; k < n; ++k) {
					if(direction(a[i], a[j], a[k]) == 0) {
						lines[i][j].push_back(k);
						f = 1;
					}
				}
				if(f) taken.push_back(line (a[i], a[j]));
			}
		}

		if(taken.size()) {
			printf("The following lines were found:\n");
			for(int i = 0; i < n; ++i) {
				for(int j = i+1; j < n; ++j) {
					if(lines[i][j].size()) printf("(%4d,%4d)(%4d,%4d)", a[i].x, a[i].y, a[j].x, a[j].y);
					for(int k = 0; k < lines[i][j].size(); ++k) {
						printf("(%4d,%4d)", a[lines[i][j][k]].x, a[lines[i][j][k]].y);
					}
					if(lines[i][j].size()) printf("\n");
				}
			}
		}
		else printf("No lines were found\n");
	}
	return 0;
}
