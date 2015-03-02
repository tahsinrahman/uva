#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][10001], a[1001], taken[1001][10001];

void path(int i, int w)
{
	if(i == n) return;

	if(taken[i][w] == 1) {
		printf("port\n");
		path(i+1, w-a[i]);
	}
	else if(taken[i][w] == 0) {
		printf("starboard\n");
		path(i+1, w);
	}
}

int f(int i, int w, int ww)
{
	if(i == n) return 0;

	if(dp[i][w] != -1) return dp[i][w];

	int p = 0, q = 0;

	if(w-a[i] >= 0) p = 1+f(i+1, w-a[i], ww);
	if(ww-a[i] >= 0) q = 1+f(i+1, w, ww-a[i]);

	if(p > q) taken[i][w] = 1;
	else if(p|q) taken[i][w] = 0;

	return dp[i][w] = max(p, q);
}

int main()
{
	int t, l, x;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &l);
		l *= 100;

		n = 0;
		while(scanf("%d", &x) && x) a[n++] = x;

		memset(dp, -1, sizeof(dp));
		memset(taken, -1, sizeof(taken));

		printf("%d\n", f(0, l, l));

		path(0, l);

		if(t) printf("\n");
	}

	return 0;
}
