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
			result.push_back(c+1);

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
	bt(0);
	int a[8];
	int cs = 0;

	while(scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]) == 8) {
		int mx, mxx;
		mxx = INT_MAX;
		for(int i = 0; i < ans.size(); i++) {
			mx = 0;
			for(int j = 0; j < 8; j++) {
				if(ans[i][j] != a[j]) mx++;
			}
			mxx = min(mxx, mx);
		}
		printf("Case %d: %d\n", ++cs, mxx);
	}
	return 0;
}
