#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100], ff[100], dp[100][10205];

int f(int i, int w)
{
	if(i == n) return 0;

	if(dp[i][w] != -1) return dp[i][w];

	int pp = 0, qq = 0;

	if(w+p[i] <= m) pp = ff[i] + f(i+1, w+p[i]);
	else if(w+p[i] > 2000 && w+p[i] <= m+200) pp = ff[i] + f(i+1, w+p[i]);
	qq = f(i+1, w);

	return dp[i][w] = max(pp, qq);
}

int main()
{
	while(scanf("%d%d", &m, &n) == 2) {
		for(int i = 0; i < n; i++) scanf("%d%d", &p[i], &ff[i]);

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, 0));
	}

	return 0;
}
