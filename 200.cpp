#include <bits/stdc++.h>
using namespace std;

int vis[27];
vector <int> order, edge[27];
set <int> s;
set <int>::iterator it;

void DFS(int u) {
	vis[u] = 1;
	for(int i = 0, s = edge[u].size(); i < s; ++i) if(!vis[edge[u][i]]) DFS(edge[u][i]);
	order.push_back(u);
}

void topsort() {
	for(it = s.begin(); it != s.end(); ++it) if(!vis[(*it)]) DFS(*it);
	reverse(order.begin(), order.end());

	for(int i = 0; i < order.size(); ++i) printf("%c", (char) order[i]+'A');
	printf("\n");
}

int main() {
//	freopen("a.txt", "r", stdin);

	string a, b;

	cin >> b;
	while(cin >> a) {
		if(a[0] == '#') break;

		for(int i = 0; a[i] && b[i]; ++i) {
			if(a[i] != b[i]) {
				edge[b[i]-'A'].push_back(a[i]-'A');
				s.insert(a[i]-'A');
				s.insert(b[i]-'A');
				break;
			}
		}
		b = a;
	}

	topsort();

	return 0;
}
