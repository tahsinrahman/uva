#include <bits/stdc++.h>
using namespace std;

int taken[10][10];
vector <int> result;
vector <vector <int> > ans;

void bt(int r)
{
	if(result.size() == 8) {
		ans.push_back(result);
		return;
	}

	for(int c = 0; c < 8; c++) {
		if(!taken[r][c]) {
			for(int i = 0; i < 8; i++) taken[r][i]++, taken[i][c]++;
			for(int i = r, j = c; i < 8 && j < 8; i++, j++) taken[i][j]++;
			for(int i = r, j = c; i < 8 && j >= 0; i++, j--) taken[i][j]++;
			result.push_back(c);

			bt(r+1);

			for(int i = 0; i < 8; i++) taken[r][i]--, taken[i][c]--;
			for(int i = r, j = c; i < 8 && j < 8; i++, j++) taken[i][j]--;
			for(int i = r, j = c; i < 8 && j >= 0; i++, j--) taken[i][j]--;
			result.pop_back();
		}
	}
}

int main()
{
	int t, a, b, cs;

	bt(0);

	scanf("%d", &t);

	while(t--) {
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");

		scanf("%d%d", &a, &b);

		cs = 0;
		a--, b--;
		for(int i = 0; i < ans.size(); i++) {
			if(ans[i][b] == a) {
				printf("%2d     ", ++cs);
				for(int j = 0; j < 8; j++) printf(" %d", 1+ans[i][j]);
				printf("\n");
			}
		}
		if(t) printf("\n");
	}

	return 0;
}