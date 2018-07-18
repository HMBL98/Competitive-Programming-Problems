#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b)for(int i = a; i < b; i++)
#define forr(i,a,b)for(int i = a; i >= b; i--)

#define MAX 51

typedef long long ll;
int n,k,memo[MAX][MAX];
ll prices[MAX];

int dp(ll target){
	memset(memo,0,sizeof memo);
	forn(i,1,n+1)if((prices[i]&target) == target)memo[1][i] = 1;
	forn(i,2,k+1)
		forn(j,1,n+1)
			forn(k,1,j)
				if(memo[i-1][k] && ((prices[j]-prices[k])&target) == target)memo[i][j] = 1;

	return memo[k][n];
}

int main(){
	cin >> n >> k;
	forn(i,1,n+1){
		cin >> prices[i];
		prices[i] += prices[i-1];
	}
	ll res = 0;
	forr(i,63,0)if(dp((res|(1LL<<i))))res |= (1LL<<i);
	cout << res << "\n";
}
