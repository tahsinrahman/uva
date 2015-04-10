#include <bits/stdc++.h>
using namespace std;

int n, m, dp[101][64001], a[101];
char symbol[101];

bool f(int i, int w)
{
	if(i == n) {
		if(w == m) return 1;
		return 0;
	}

	if(dp[i][w+32000] != -1) return dp[i][w+32000];

	int p, q, r, s;
	p = q = r = s = 0;

	if(w+a[i] <= 32000) p = f(i+1, w+a[i]);
	if(!p && w-a[i] >= -32000) q = f(i+1, w-a[i]);
	if(!p && !q && w*a[i] <= 32000 && w*a[i] >= -32000) r = f(i+1, w*a[i]);
	if(!p && !q && !r && w%a[i] == 0) s = f(i+1, w/a[i]);

	if(p) symbol[i] = '+';
	else if(q) symbol[i] = '-';
	else if(r) symbol[i] = '*';
	else if(s) symbol[i] = '/';

	return dp[i][w+32000] = p||q||r||s;
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

		scanf("%d", &m);

		memset(dp, -1, sizeof(dp));
		if(f(1, a[0])) {
			printf("%d", a[0]);
			for(int i = 1; i < n; ++i) printf("%c%d", symbol[i], a[i]);
			printf("=%d\n", m);
		}
		else printf("NO EXPRESSION\n");
	}

	return 0;
}
