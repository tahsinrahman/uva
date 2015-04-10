#include <bits/stdc++.h>
using namespace std;

int n, dp[101][101][101];

int f(int i, int k, int w)
{
	if(k == 1) return 1;
	if(i > n) return 0;

	if(dp[i][k][w] != -1) return dp[i][k][w];
	
	int p = f(i, k-1, n-i);
	int q = f(i+1, k, n-i);

	return dp[i][k][w] = (p+q)%1000000;
}

int main()
{
	int k;

	while(scanf("%d%d", &n, &k)) {
		if(!n && !k) break;

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, k, n));
	}

	return 0;
}
