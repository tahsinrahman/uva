#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[61][61];

unsigned long long f(int n, int m)
{
	if(n <= 1) return 1;

	if(dp[n][m]) return dp[n][m];

	unsigned long long sum = 1;
	for(int i = 1; i <= m; ++i) sum += f(n-i, m);
	return dp[n][m] = sum;
}

int main()
{
	int n, m, cs = 0;
	while(scanf("%d%d", &n, &m) && n < 61) printf("Case %d: %llu\n", ++cs, f(n, m));

	return 0;
}
