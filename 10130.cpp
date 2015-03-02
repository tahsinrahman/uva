#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000][31], p[1000], w[1000];

int f(int i, int weight)
{
	if(i == n) return 0;

	if(dp[i][weight] != -1) return dp[i][weight];

	int pp = 0, qq = 0;

	if(weight-w[i] >= 0) pp = p[i] + f(i+1, weight-w[i]);
	qq = f(i+1, weight);

	return dp[i][weight] = max(pp, qq);
}

int main()
{
	int t, sum, x, m;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 0; i < n; i++) scanf("%d%d", &p[i], &w[i]);

		scanf("%d", &m);

		memset(dp, -1, sizeof(dp));

		sum = 0;
		while(m--) {
			scanf("%d", &x);
			sum += f(0, x);
		}
		printf("%d\n", sum);
	}

	return 0;
}
