#include<bits/stdc++.h>
using namespace std;

int f, ans, result;
int taken[15], a[15];

void bt()
{
	if(f) return;

	if(result == 5) {
		if(ans == 23) f = 1;
		return;
	}

	for(int i = 0; i < 5; i++) {
		if(!taken[i]) {
			taken[i] = 1;
			result++;

			ans += a[i];
			bt();
			ans -= a[i];

			ans *= a[i];
			bt();
			ans /= a[i];

			ans -= a[i];
			bt();
			ans += a[i];

			result--;
			taken[i] = 0;
		}
	}
}

int main()
{
	while(1) {
		for(int i = 0; i < 5; i++) scanf("%d", &a[i]);
		if(!a[0] && !a[1] && !a[2] && !a[3] && !a[4]) break;

		result = 2;
		f = 0;
		for(int i = 0; i < 5; i++) {
			for(int j = i+1; j < 5; j++) {
				taken[i] = taken[j] = 1;
				ans = a[i]+a[j];
				bt();

				ans = a[i]*a[j];
				bt();

				ans = a[i]-a[j];
				bt();
			
				taken[i] = taken[j] = 0;
			}
			for(int j = 0; j < i; j++) {
				taken[i] = taken[j] = 1;
				ans = a[i]-a[j];
				bt();
				taken[i] = taken[j] = 0;
			}
		}

		if(f) printf("Possible\n");
		else printf("Impossible\n");
	}
	
	return 0;
}