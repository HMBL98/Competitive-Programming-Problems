#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define MAX 2000+10
typedef long long ll;
ll a,n,m,umb[MAX],rain[MAX],cost[MAX],memo[MAX][MAX];
const ll inf = 1ll<<40;

ll dp(int pos,int um){
	if(pos == a)return 0;
	ll &res = memo[pos][um];
	if(res != -1)return res;
	res = inf;
	if(rain[pos]){
		if(um != m)res = min(res,cost[um]+dp(pos+1,um));
	}else{
		if(um != m)res = min(res,cost[um]+dp(pos+1,um));
		res = min(res,dp(pos+1,m));
	}
	if(umb[pos] != -1){
		res = min(res,cost[umb[pos]]+dp(pos+1,umb[pos]));
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> n >> m;
	forn(i,0,n){
		int l,r; cin >> l >> r;
		forn(j,l,r)rain[j] = 1;
	}
	forn(i,0,a+1)umb[i] = -1;
	forn(i,0,m){
		int x,c; cin >> x >> c;
		cost[i] = c;
		if(umb[x] == -1) umb[x] = i;
		else umb[x] = (cost[umb[x]] < c) ? umb[x] : i;
	}
	forn(i,0,a+1)forn(j,0,m+1)memo[i][j] = -1;
	ll res = dp(0,m);
	cout << ((res == inf) ? -1 : res) << "\n";
}
