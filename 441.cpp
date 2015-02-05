#include<bits/stdc++.h>
using namespace std;

int n;
int taken[50], a[50];
vector <int> result;

void bt(int idx)
{
	if(result.size() == 6) {
		printf("%d", result[0]);
		for(int i = 1; i < 6; i++) printf(" %d", result[i]);
		printf("\n");
		return;
	}

	for(int i = idx; i < n; i++) {
		if(!taken[i]) {
			taken[i] = 1;
			result.push_back(a[i]);

			bt(i+1);

			result.pop_back();
			taken[i] = 0;
		}
	}
}

int main()
{
	int f = 0;

	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		if(f) printf("\n");
		bt(0);
		f = 1;
	}

	return 0;
}