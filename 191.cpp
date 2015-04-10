#include <bits/stdc++.h>
using namespace std;

bool insideRectangle(pair <int, int> a, pair<int, int> b, pair<int, int> c)
{
	return (a.first <= c.first && c.first <= b.first && b.second <= c.second && c.second <= a.second);
}

bool onSegment(pair <int ,int> a, pair<int ,int> b, pair<int, int> c)
{
	return min(a.first, b.first) <= c.first && c.first <= max(a.first, b.first) && min(a.second, b.second) <= c.second && c.second <= max(a.second, b.second); 
}

int direction(pair <int, int> a, pair<int, int> b, pair <int, int> c)
{
	return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}

bool segmentIntersect(pair <int, int> a, pair<int, int> b, pair<int, int> c, pair <int, int> d)
{
	int d1 = direction(c, d, a);
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);

	if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0))) return true;
	if(d1 == 0 && onSegment(c, d, a)) return true;
	if(d2 == 0 && onSegment(c, d, b)) return true;
	if(d3 == 0 && onSegment(a, b, c)) return true;
	if(d4 == 0 && onSegment(a, b, d)) return true;
	return false;
}

int main()
{
	int t;
	pair <int, int> a, b, c, d, p, q;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d%d%d%d%d%d", &p.first, &p.second, &q.first, &q.second, &a.first, &a.second, &b.first, &b.second);

		pair <int, int> x, y;
		x.first = min(a.first, b.first);
		x.second = max(a.second, b.second);
		y.first = max(a.first, b.first);
		y.second = min(a.second, b.second);

		a = x;
		b = y;

		c = make_pair(b.first, a.second);
		d = make_pair(a.first, b.second);

//		cout << a.first << ' ' << c.first << ' ' << b.first << ' ' << b.second << ' ' << c.second << ' ' << a.second << endl;
//		cout << insideRectangle(a, b, p) << endl;

		if(segmentIntersect(p, q, a, c) || segmentIntersect(p, q, a, d) || segmentIntersect(p, q, b, d) || segmentIntersect(p, q, b, c) || insideRectangle(a, b, p) || insideRectangle(a, b, q)) printf("T\n");
		else printf("F\n");
	}

	return 0;
}
