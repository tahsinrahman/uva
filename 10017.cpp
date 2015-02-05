#include <bits/stdc++.h>
using namespace std;

int cnt, m;
vector <int> st[3];

bool check(int x, int y)
{
	if(st[x].size() == 0) return false;
	if(st[y].size() == 0) return true;
	if(st[y][st[y].size()-1] > st[x][st[x].size()-1]) return true;
	return false;
}

void add(int x, int y)
{
	st[y].push_back(st[x][st[x].size()-1]);
	st[x].pop_back();
}

void print()
{
	printf("\n");
	for(int i = 0; i < 3; i++) {
		printf("%c=>", i+'A');
		if(st[i].size()) printf("   %d", st[i][0]);
		for(int j = 1; j < st[i].size(); j++) printf(" %d", st[i][j]);
		printf("\n");
	}
	cnt++;
}



void bt(int n, int x)
{
//	if(!st[0].size() && !st[1].size()) return;

	int tmp;
	if(check(n, (n+1+x)%3)) {
		add(n, (n+1+x)%3);
		tmp = (n+2+x*2)%3;
		print();
	}

	if(cnt == m) return;

	if(check(n, (n+2+x*2)%3)) {
		add(n, (n+2+x*2)%3);
		tmp = (n+1+x)%3;
		print();
	}

	if(cnt == m) return;

	bt(tmp, x);
}

int main()
{
	int n, cs = 0;

	while(scanf("%d%d", &n, &m)) {
		if(!n && !m) break;

		for(int i = 0; i < 3; i++) st[i].clear();

		for(int i = n; i; i--) st[0].push_back(i);

		cnt = -1;

		printf("Problem #%d\n", ++cs);

		print();

		if(n == 1 && m) {
			st[0].clear();
			st[2].push_back(1);
			print();
		}
		else if(n > 1 && m) bt(0, n&1);

		printf("\n");
	}

	return 0;
}