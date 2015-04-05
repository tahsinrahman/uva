#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1010];

bool check(int m)
{
	int i = 0, cnt = 0;

	while(i < n) {
		int sum = 0;
		while(i < n && sum+a[i] <= m) {
			sum += a[i];
			++i;
		}
		++cnt;
	}
	if(cnt <= k) return 1;
	return 0;
}

int bs(int l, int h)
{
	int ans;
	while(l <= h) {
		int m = l + ((h-l)>>1);

		if(check(m)) { ans = m; h = m-1; }
		else l = m+1;
	}
	return ans;
}


int main()
{
	int t, cs = 0;

	while(~scanf("%d%d", &n, &k)) {

		int mx = 0, sum = 0;
		for(int i = 0; i < n; ++i) { scanf("%d", &a[i]); mx = max(mx, a[i]); sum += a[i]; }

		printf("%d\n", bs(mx, sum));
	}

	return 0;
}
