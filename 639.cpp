#include <bits/stdc++.h>
using namespace std;

int n, result, mx, x, mmx, ff;
int taken[10][10];
char a[10][10];
vector <pair<int, int> > ans;
vector < vector <pair <int, int> > > mxx;

void update(int r, int c, int x)
{
	for(int i = c; i < n; i++) {
		if(a[r][i] == 'X') break;
		taken[r][i] += x;
	}
	for(int i = c; i >= 0; i--) {
		if(a[r][i] == 'X') break;
		taken[r][i] += x;
	}
	
	for(int i = r; i < n; i++) {
		if(a[i][c] == 'X') break;
		taken[i][c] += x;
	}
	for(int i = r; i >= 0; i--) {
		if(a[i][c] == 'X') break;
		taken[i][c] += x;
	}
}


void bt(int r)
{
	if(r == n) {
		if(result > mx) {
			mx = result;
			if(ff) mxx.clear();
			if(ff) mxx.push_back(ans);
		}
		else if(result == mx) if(ff) mxx.push_back(ans);
		return;
	}

	int f = 1;
	for(int c = 0; c < n; c++) {
		if(a[r][c] != 'X' && !taken[r][c]) {
			f = 0;

			update(r, c, 1);
			result++;
			ans.push_back(make_pair(r, c));

			bt(r+1);

			update(r, c, -1);
			result--;
			ans.pop_back();
		}
	}
	if(f) bt(r+1);
}

void fff()
{
	mmx = 0;
	for(int i = 0; i < mxx.size(); i++) {
		for(int j = 0; j < mxx[i].size(); j++) {
			update(mxx[i][j].first, mxx[i][j].second, 1);
//			cout << mxx[i][j].first << ' ' << mxx[i][j].second << endl;
		}

		result = 0;
		mx = 0;
		ff = 0;
		bt(0);

		mmx = max(mmx, mx);
		for(int j = 0; j < mxx[i].size(); j++) update(mxx[i][j].first, mxx[i][j].second, -1);
	}
	x += mmx;
}
	
	
	
int main()
{
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; i++) scanf("%s", a[i]);

		result = 0, mx = 0;
		memset(taken, 0, sizeof(taken));
		ff = 1;
		bt(0);
		x = mx;
		fff();

		printf("%d\n", x);
	}

	return 0;
}