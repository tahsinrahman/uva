#include <bits/stdc++.h>
using namespace std;

int w, n;
int a[22], dp[21][5000], taken[21][5000];

void printPath(int i, int w)
{
	if(i == n) return;

	if(taken[i][w]) {
		printf("%d ", a[i]);
		printPath(i+1, w-a[i]);
	}
	else printPath(i+1, w);
}



int f(int i, int w)
{
	if(i == n) return 0;

	if(dp[i][w] != -1) return dp[i][w];

	int p = 0, q = 0;

	if(w-a[i] >= 0) p = a[i] + f(i+1, w-a[i]);
	q = f(i+1, w);

	if(p > q) taken[i][w] = 1;

	return dp[i][w] = max(p, q);
}

int main()
{
	while(scanf("%d%d", &w, &n) == 2) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		memset(dp, -1, sizeof(dp));
		memset(taken, 0, sizeof(taken));

		int sum = f(0, w);
		printPath(0, w);
		printf("sum:%d\n", sum);
	}

	return 0;
}
