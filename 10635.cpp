#include <bits/stdc++.h>
using namespace std;

int n;
int a[62510], b[62510];

int bs(int h, int n) {
	int l = 1, ans = 0;

	while(l <= h) {
		int m = (l+h)>>1;

		if(a[b[m]] < n) {
			l = m+1;
			ans = m;
		}
		else h = m-1;
	}
	return ans+1;
}

int LIS() {
	int len = 0;
	for(int i = 0; i < n; ++i) {
		int newLen = bs(len, a[i]);
		b[newLen] = i;
		len = max(len, newLen);
	}
	return len;
}

int main() {
	int t, p, q, cs = 0, x;

	scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d", &n, &p, &q);
		++p;
		++q;

		vector <int> idx(n*n+10);
		for(int i = 1; i <= p; ++i) {
			scanf("%d", &x);
			idx[x] = i;
		}

		n = 0;
		for(int i = 0; i < q; ++i) {
			scanf("%d", &x);
			if(idx[x]) a[n++] = idx[x];
		}

		printf("Case %d: %d\n", ++cs, LIS());
	}

	return 0;
}
