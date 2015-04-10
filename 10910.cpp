#include <bits/stdc++.h>
using namespace std;

int n, t, p, mx, dp[71][71];

int f(int i, int w)
{
	if(i == n) {
		if(!w) return 1;
		return 0;
	}

	if(dp[i][w] != -1) return dp[i][w];

	int sum = 0;
	for(int j = p; w-j >= 0 && j <= mx; ++j) sum += f(i+1, w-j);

	return dp[i][w] = sum;
}

int main()
{
	int T;

	scanf("%d", &T);

	while(T--) {
		scanf("%d%d%d", &n, &t, &p);

		mx = t-p*(n-1);

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, t));
	}

	return 0;
}
