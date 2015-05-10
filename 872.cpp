#include <bits/stdc++.h>
using namespace std;

int n, flag, taken[21], edge[21][21];
vector <int> res;
map <char, int> mp;
map <int, char> mp1;

bool check(int u) {
	for(int i = 0, s = res.size(); i < s; ++i) if(edge[u][res[i]]) return 0;
//	for(int i = 0; i < res.size(); ++i) cout << mp1[u] << ' ' << mp1[res[i]] << ' ' << edge[u][res[i]] << endl;
//	cout << endl;
	return 1;
}

void bt() {
	if(res.size() == n) {
		flag = 0;
		printf("%c", mp1[res[0]]);
		for(int i = 1; i < n; ++i) printf(" %c", mp1[res[i]]);
		printf("\n");
		return;
	}

	for(int i = 0; i < n; ++i) {
		if(!taken[i] && check(i)) {
			taken[i] = 1;
			res.push_back(i);

			bt();

			res.pop_back();
			taken[i] = 0;
		}
	}
}

int main() {
//	freopen("a.txt", "r", stdin);

	int t;
	string a, tmp;
	char u[21], v, uu;
	int f = 0;

	scanf("%d", &t);
	getchar();
//	while(getline(cin, a)) {
	while(t--) {
		getchar();
		getline(cin, a);

		stringstream ss(a);
		n = 0;
		while(ss >> u[n]) {
//			mp[u] = n;
//			mp1[n] = u;
			++n;
		}

		sort(u, u+n);
		for(int i = 0; i < n; ++i) { mp[u[i]] = i; mp1[i] = u[i]; }
//		for(int i = 0; i < n; ++i) cout << u[i] << endl;

		getline(cin, a);
		stringstream sss(a);
		while(sss >> tmp) {
			edge[mp[tmp[0]]][mp[tmp[2]]] = 1;
		}

		flag = 1;
		bt();
		if(flag) printf("NO\n");
		if(t) printf("\n");


		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) edge[i][j] = 0;
		mp.clear();
		mp1.clear();
	}

	return 0;
}
