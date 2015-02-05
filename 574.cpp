#include<bits/stdc++.h>
using namespace std;

int t, sum, n, f;
int taken[15], a[15];
vector <int> result;

void bt(int idx)
{
	if(sum == t) {
		f = 0;
		printf("%d", result[0]);
		for(int i = 1; i < result.size(); i++) printf("+%d", result[i]);
		printf("\n");
		return;
	}

	int i = idx;
	while(i < n) {
		if(sum+a[i] <= t) {
			result.push_back(a[i]);
			sum += a[i];

			bt(i+1);

			result.pop_back();
			sum -= a[i];
		}
		int key = a[i];
		while(a[i] == key) i++;
	}
}


int main()
{
	while(scanf("%d%d", &t, &n) && n) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		printf("Sums of %d:\n", t);
		f = 1;
		bt(0);

		if(f) printf("NONE\n");
	}

	return 0;
}