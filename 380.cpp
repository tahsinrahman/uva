#include <bits/stdc++.h>
using namespace std;

vector <pair<int, pair<int, int> > > edge[10000];
int timee, taken[10000], ans;

void bt(int source)
{
	int f = 0;
	ans = source;
	taken[source] = 1;
	for(int i = 0; i < edge[source].size(); i++) {
		int start = edge[source][i].second.first;
		int end = edge[source][i].second.second;
		int number = edge[source][i].first;

		if(start <= timee && timee <= end) {
			f = 1;
			if(taken[number] == 0) bt(number);
			else ans = 9999;
		}
		if(f) break;
	}
	taken[source] = 0;
}


int main()
{
	int t, source, duration, target, cs = 0;

	scanf("%d", &t);

	printf("CALL FORWARDING OUTPUT\n");
	while(t--) {
		printf("SYSTEM %d\n", ++cs);

		while(scanf("%d", &source)) {
			if(source == 0) break;

			scanf("%d%d%d", &timee, &duration, &target);

			edge[source].push_back(make_pair(target, make_pair(timee, timee+duration)));
		}

		while(scanf("%d", &timee)) {
			if(timee == 9000) break;
			

			scanf("%d", &source);
		
			bt(source);

			printf("AT %04d CALL TO %04d RINGS %04d\n", timee, source, ans);
		}
		for(int i = 0; i <= 9999; i++) edge[i].clear();
	}
	printf("END OF OUTPUT\n");

	return 0;
}
