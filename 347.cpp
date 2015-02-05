#include <bits/stdc++.h>
using namespace std;

int taken[10];
vector <int> v, r;

void check(vector <int> rr)
{
	int s = rr.size();
	vector <int> vis(s);

	int p = (rr[0])%s;
	while(!vis[p]) {
		vis[p] = 1;
		p = (p+rr[p])%s;
	}
	for(int i = 0; i < s; i++) if(!vis[i]) return;

	int tmp = 0;
	for(int i = 0; i < s; i++) tmp = tmp*10 + rr[i];
	v.push_back(tmp);
}

void bt()
{
	if(r.size() > 6) return;

	for(int i = 1; i <= 9; i++) {
		if(!taken[i]) {
			taken[i] = 1;
			r.push_back(i);

			check(r);
			bt();

			r.pop_back();
			taken[i] = 0;
		}
	}
}


int main()
{
	int n, ans, cs = 0;

	bt();

	sort(v.begin(), v.end());

	while(scanf("%d", &n) && n) {
		int idx = upper_bound(v.begin(), v.end(), n)-v.begin();
		if(v[idx-1] == n) ans = n;
		else ans = v[idx];
		printf("Case %d: %d\n", ++cs, ans);
	}

	return 0;
}