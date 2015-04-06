#include <bits/stdc++.h>
using namespace std;

int n, m, a[1010], dp[1001][1001];

int f(int i, int w)
{
	if(w > n-i) return 0;
	if(!w) return 1;

	if(dp[i][w] != -1) return dp[i][w];

	return dp[i][w] = (((long long)a[i]*f(i+1, w-1))%m + f(i+1, w))%m;
}

int main()
{
	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		for(int i = 0; i < n; ++i) scanf("%d", a+i);

		memset(dp, -1, sizeof(dp));

		int mx = 0;
		for(int i = 1; i <= n; ++i) mx = max(mx, f(0, i));

		printf("%d\n", mx);
	}

	return 0;
}
