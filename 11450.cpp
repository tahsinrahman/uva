#include <bits/stdc++.h>
using namespace std;

int c, m, k[21], a[21][21], dp[21][21][201];

int f(int i, int j, int w)
{

	if(i == c) return 0;
	if(j == k[i]) return 0;

	if(dp[i][j][w] != -1) return dp[i][j][w];

	int p = 0, q = 0;
	if(w+a[i][j] <= m) p = a[i][j] + f(i+1, 0, w+a[i][j]);
	q = f(i, j+1, w);

	return dp[i][j][w] = max(p, q);
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &m, &c);

		int mn, sum = 0;
		for(int i = 0; i < c; ++i) {
			scanf("%d", &k[i]);
			mn = INT_MAX;
			for(int j = 0; j < k[i]; ++j) { scanf("%d", &a[i][j]); mn = min(mn, a[i][j]); }
			sum += mn;
		}
		if(sum > m) { printf("no solution\n"); continue; }

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, 0, 0));
	}

	return 0;
}
