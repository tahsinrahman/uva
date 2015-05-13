#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
char a[1001], b[1001];

int main() {
	dp[0][0] = 0;
	for(int i = 1; i <= 1000; ++i) dp[i][0] = i;
	for(int i = 1; i <= 1000; ++i) dp[0][i] = i;

	int n, m;
	while(scanf("%d %s", &n, a) != EOF) {
		scanf("%d %s", &m, &b);
	
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = min(1+min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (a[i-1] != b[j-1]));

		printf("%d\n", dp[n][m]);
	}

	return 0;
}
