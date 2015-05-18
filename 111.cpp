#include <bits/stdc++.h>
using namespace std;

int a[100], b[100], dp[100][100];

int main() {
	int n, x;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[x-1] = i;
	}

	while(scanf("%d", &x) == 1) {
		b[x-1] = 0;
		for(int i = 1; i < n; ++i) {
			scanf("%d", &x);
			b[x-1] = i;
		}

		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(a[i-1] == b[j-1]));

		printf("%d\n", dp[n][n]);
	}

	return 0;
}
