#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator () (const string &a, const string &b) const {
		if(a.length() == b.length()) return a < b;
		return a.length() < b.length();
	}
};

int fx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int fy[] = {0, 1, 0, -1, 1, -1, -1, 1};

int n;
int taken[25][25];
char a[25][25];
vector <char> result;
set <string, cmp> s;
set <string>::iterator it;

void bt(int x, int y)
{
	result.push_back(a[x][y]);
	taken[x][y] = 1;

	for(int i = 0; i < 8; i++) {
		int xx = x + fx[i];
		int yy = y + fy[i];

		if(xx >= 0 && xx < n && yy >= 0 && yy < n && !taken[xx][yy] && a[xx][yy] > a[x][y]) bt(xx, yy);
	}

	if(result.size() > 2) {
		string a = "";
		for(int i = 0; i < result.size(); i++) a += result[i];
		s.insert(a);
	}

	taken[x][y] = 0;
	result.pop_back();
}

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 0; i < n; i++) scanf("%s", a[i]);

		s.clear();
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) bt(i, j);

		for(it = s.begin(); it != s.end(); ++it) cout << *it << endl;
		if(t) printf("\n");
	}

	return 0;
}
