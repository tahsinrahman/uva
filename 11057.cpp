#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;

	while(scanf("%d", &n) == 1) {
		int a[n];

		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		sort(a, a+n);

		scanf("%d", &m);

		pair <int, int> ans;

		int mn = INT_MAX;
		for(int i = 0; i < n; ++i) if(binary_search(a+i, a+n, m-a[i])) if(m-a[i]*2 < mn) ans = make_pair(a[i], m-a[i]);

		printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
	}

	return 0;
}
