#include<bits/stdc++.h>
using namespace std;

int n;
int taken[20], primes[50];
vector <int> result;

void bt()
{
	if(result.size() == n) {
		if(primes[1+result[result.size()-1]]) {
			printf("1");
			for(int i = 1; i < n; i++) printf(" %d", result[i]);
			printf("\n");
		}
		return;
	}

	for(int i = 2; i <= n; i++) {
		if(!taken[i] && primes[result[result.size()-1]+i]) {
			taken[i] = 1;
			result.push_back(i);

			bt();

			result.pop_back();
			taken[i] = 0;
		}
	}
}


int main()
{
	int cs = 0;
	primes[2] = primes[3] = primes[5] = primes[7] = primes[11] = primes[13] = primes[17] = primes[19] = primes[23] = primes[29] = primes[31] = 1;

	result.push_back(1);


	int f = 0;
	while(scanf("%d", &n) == 1) {
		if(f) printf("\n");
		printf("Case %d:\n", ++cs);
		bt();
		f = 1;
	}
	
	return 0;
}
