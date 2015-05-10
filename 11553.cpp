#include <bits/stdc++.h>
using namespace std;

int n;
int a[8][8], dp[1<<8][1<<8];

bool checkBit(int n, int i) { return n&(1<<i); }
int setBit(int n, int i) { return n|(1<<i); }

int f(int mask1, int mask2) {
	if(mask1 == (1<<n)-1 && mask2 == (1<<n)-1) return 0;
	if(dp[mask1][mask2] != -1) return dp[mask1][mask2];

	int mx = INT_MIN, mn = INT_MAX;
	for(int i = 0; i < n; ++i) {
		if(checkBit(mask1, i)) continue;
		for(int j = 0; j < n; ++j) {
			if(checkBit(mask2, j)) continue;
			mn = min(mn, a[i][j] + f(setBit(mask1, i), setBit(mask2, j)));
		}
		mx = max(mx, mn);
	}

	return dp[mask1][mask2] = mx;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, 0));
	}

	return 0;
}
