#include <bits/stdc++.h>
using namespace std;

int dp[27][27][686];

int f(int i, int n, int m)
{
	if(!m && !n) return 1;
	if(!n) return 0;
	if(i == 27) return 0;

	if(dp[i][n][m] != -1) return dp[i][n][m];

	int p, q;
	p = q = 0;
	
	if(m-i >= 0) p = f(i+1, n-1, m-i);
	q = f(i+1, n, m);
	
	return dp[i][n][m] = p+q;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	int n, m, cs = 0;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		if(n > 26 || m > 351) printf("Case %d: %d\n", ++cs, 0);
		else printf("Case %d: %d\n", ++cs, f(1, n, m));
	}

	return 0;
}
