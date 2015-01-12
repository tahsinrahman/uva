#include <bits/stdc++.h>
using namespace std;

vector <int> e[100000];
vector <pair<int, int> > cost[100000];
int n, x;

struct data {
	int city, init;
	vector <int> dist[26];
};

int dijkstra()
{
	vector <vector <int> > d(n+1, vector <int> (26));
	for(int i = 2; i <= n; i++) for(int j = 0; j < 26; j++) d[i][j] = 1000000;

	data u, v;
	u.init = x;
	u.city = 1;

	queue <data> q;
	q.push(u);

	while(!q.empty()) {
		u = q.front();
		q.pop();

		for(int i = 0; i < e[u.city].size(); i++) {
			v.city = e[u.city][i];
			v.init = cost[u.city][i].second;

			int f = 0;
			for(int j = 0; j < 26; j++) {
				if(j == v.init) continue;
				if(cost[u.city][i].first + d[u.city][j] < d[v.city][v.init]) {
					d[v.city][v.init] = cost[u.city][i].first + d[u.city][j];
					f = 1;
				}
			}
			if(f) q.push(v);
		}
	}
	sort(d[2].begin(), d[2].end());
	if (d[2][0] >= 1000000) return -1;
	return d[2][0];

}

int main()
{
	int m, u, v, ans; 
	string a, b, c;
	
	while(scanf("%d", &m) && m) {
		map <string, int> mp;

		cin >> a >> b;
		mp[a] = 1;
		mp[b] = 2;
		x = a[0]-'a';

		n = 3;
		while(m--) {
			cin >> a >> b >> c;
			u = mp[a];
			v = mp[b];
			if(!u) u = mp[a] = n++;
			if(!v) v = mp[b] = n++;
			e[u].push_back(v);
			e[v].push_back(u);
			cost[u].push_back(make_pair(c.length(), c[0]-'a'));
			cost[v].push_back(make_pair(c.length(), c[0]-'a'));
		}

		ans = dijkstra();
		
		if(ans == -1) printf("impossivel\n");
		else printf("%d\n", ans);

		for(int i = 0; i <= n; i++) {
			e[i].clear();
			cost[i].clear();
		}

	}

	return 0;
}
