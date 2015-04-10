#include <bits/stdc++.h>
using namespace std;

int n, m, k; 
long long dp[51][51][51];

long long f(int group, int groupWidth, int totalWidth)
{
	if(totalWidth == n) {
		if(group == k) return 1;
		return 0;
	}

	if(dp[group][groupWidth][totalWidth] != -1) return dp[group][groupWidth][totalWidth];

	long long p = 0, q = 0;

	if(groupWidth < m) p = f(group, groupWidth+1, totalWidth+1);
	if(group < k) q = f(group+1, 1, totalWidth+1);

	return dp[group][groupWidth][totalWidth] = p+q;
}

int main()
{
	while(scanf("%d%d%d", &n, &k, &m) == 3) {
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", f(1, 1, 1));
	}

	return 0;
}
