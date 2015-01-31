#include<bits/stdc++.h>
using namespace std;

int r, len;
char a[100];
vector <char> result;

void bt(int s)
{
	if(result.size() == r) {
		for(int i = 0; i < r; i++) printf("%c", result[i]);
		printf("\n");
		return;
	}

	int i = s;
	while(i < len) {
		result.push_back(a[i]);
		bt(i+1);
		result.pop_back();
		i = upper_bound(a, a+len, a[i])-a;
	}
}
		

int main()
{
	while(scanf("%s", a) != EOF) {
		scanf("%d", &r);
		len = strlen(a);

		sort(a, a+len);

		bt(0);
	}

	return 0;
}
