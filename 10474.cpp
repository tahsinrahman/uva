#include <bits/stdc++.h>
using namespace std;

int a[100000], n;

int bs(int x)
{
	int l = 0, h = n-1;

	int ans = -1;
	while(l <= h) {
		int m = l + ((h-l)>>1);

		if(x <= a[m]) {
			if(a[m] == x) ans = m;
			h = m-1;
		}
		else l = m+1;
	}
	return ans+1;
}

int main()
{
	int q, x, cs = 0;

	while(scanf("%d%d", &n, &q)) {
		if(!n && !q) break;

		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		sort(a, a+n);

		printf("CASE# %d:\n", ++cs);
		while(q--) {
			scanf("%d", &x);
			int ans = bs(x);
			if(ans) printf("%d found at %d\n", x, ans);
			else printf("%d not found\n", x);
		}
	}

	return 0;
}
