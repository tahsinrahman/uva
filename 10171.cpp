#include <bits/stdc++.h>
using namespace std;

int ydis[30][30], mdis[30][30];

int main()
{
//	freopen("a.txt", "r", stdin);

	char u, v, a, d;
	int n, w, mn;
	vector <int> meet;

	while(scanf("%d", &n) && n) {
		getchar();

		for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) if(i != j) ydis[i][j] = mdis[i][j] = 10000000;

		while(n--) {
			scanf("%c %c %c %c %d", &a, &d, &u, &v, &w);
			getchar();

			if(a == 'Y') {
				ydis[u-'A'][v-'A'] = min(ydis[u-'A'][v-'A'], w);
				if(d == 'B') ydis[v-'A'][u-'A'] = min(ydis[v-'A'][u-'A'], w);
			}
			else {
				mdis[u-'A'][v-'A'] = min(mdis[u-'A'][v-'A'], w);
				if(d == 'B') mdis[v-'A'][u-'A'] = min(mdis[v-'A'][u-'A'], w);
			}
		}

		for(int k = 0; k < 26; k++) 
			for(int i = 0; i < 26; i++) 
				for(int j = 0; j < 26; j++) {
					ydis[i][j] = min(ydis[i][j], ydis[i][k] + ydis[k][j]);
					mdis[i][j] = min(mdis[i][j], mdis[i][k] + mdis[k][j]);
				}

		scanf("%c %c", &u, &v);
		getchar();

		mn = INT_MAX;
		for(int i = 0; i < 26; i++) {
			if(ydis[u-'A'][i] + mdis[v-'A'][i] < mn) {
				mn = ydis[u-'A'][i] + mdis[v-'A'][i];
				meet.clear();
				meet.push_back(i);
			}
			else if(ydis[u-'A'][i] + mdis[v-'A'][i] == mn) meet.push_back(i);
		}

		if(mn < 10000000) {
			printf("%d %c", mn, meet[0]+'A');
			for(int i = 1; i < meet.size(); i++) printf(" %c", meet[i]+'A');
			printf("\n");
		}
		else printf("You will never meet.\n");

		meet.clear();
	}

	return 0;
}
