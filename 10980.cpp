#include <bits/stdc++.h>
using namespace std;

int n, a[1000];
double b[1000], dp[102][102];

double f(int i, int w)
{
	if(w <= 0) return 0;
	if(i > n) return 100000;

	if(dp[i][w]) return dp[i][w];

	double p = b[i] + f(i, w-a[i]);
	double q = f(i+1, w);

	return dp[i][w] = min(p, q);
}

int main()
{
	int cs = 0;
	double u;

	while(scanf("%lf%d", &u, &n) == 2) {
		a[0] = 1; b[0] = u;

		for(int i = 1; i <= n; ++i) scanf("%d%lf", a+i, b+i);
		getchar();

		string str;
		getline(cin, str);
		
		stringstream ss(str);

		memset(dp, 0, sizeof(dp));
		printf("Case %d:\n", ++cs);

		int x;
		while(ss >> x) printf("Buy %d for $%.2lf\n", x, f(0, x));
	}

	return 0;
}
