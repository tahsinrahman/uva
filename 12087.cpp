#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)

int n, k;
int a[10010];

bool check(double m)
{
	if(!m) return 1;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		cnt += (int) (a[i]/m);
		if(cnt >= k) return 1;
	}
	return 0;
}

double bs(double l, double h)
{
	while(h-l > 1e-5) {
		double m = l + (h-l)/2.0;

		if(check(m)) l = m;
		else h = m;
	}
	return l;
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &k);
		++k;

		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		for(int i = 0; i < n; ++i) a[i] *= a[i];
		sort(a, a+n);

		printf("%.4lf\n", bs(0, a[n-1])*pi);
	}

	return 0;
}
