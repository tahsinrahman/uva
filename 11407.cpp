#include <bits/stdc++.h>
using namespace std;

int a[102], dp[10002];

void generate()
{
	for(int i = 1; i < 101; ++i) a[i] = i*i;
}

int f(int i, int w)
{
	if(w == 0) return 0;
	if(a[i] > w) return 100;
	if(i == 101) return 100;

	if(dp[w] != -1) return dp[w];

	int p, q;
	p = q = INT_MAX;

	if(w-a[i] >= 0) p = 1+f(i, w-a[i]);
	q = f(i+1, w);

	return dp[w] = min(p, q);
}

int main()
{
	generate();

	int t, n;
	scanf("%d", &t);

	memset(dp, -1, sizeof(dp));
	while(t--) {
		scanf("%d", &n);

		printf("%d\n", f(1, n));
	}

	return 0;
}
