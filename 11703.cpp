#include <bits/stdc++.h>
using namespace std;

#define mod 1000000

vector <int> dp(1000010, -1);

int f(int n)
{
	if(n == 0) return 1;

	if(dp[n] != -1) return dp[n];

	return dp[n] = (f(n-sqrt(n)) + f(log(n)) + f(n*(sin(n))*(sin(n))))%mod;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n != -1) printf("%d\n", f(n));

	return 0;
}
