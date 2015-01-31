#include <bits/stdc++.h>
using namespace std;

int n, cap, a[100], dp[25002][102];

int knapsack(int w, int i)
{
	if(i == n) return 0;

	if(dp[w][i] != -1) return dp[w][i];

	int p , q;
	p = q = 0;

	if(w+a[i] <= cap) p = a[i] + knapsack(w+a[i], i+1);
	q = knapsack(w, i+1);

	return dp[w][i] = max(p, q);
}

int main()
{
//	freopen("a.txt", "r", stdin);
	int t, sum;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		cap = sum>>1;

		memset(dp, -1, sizeof(dp));

		printf("%d\n", abs(sum-2*knapsack(0, 0)));
	}

	return 0;
}
