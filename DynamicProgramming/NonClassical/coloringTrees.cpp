//C. Coloring Trees codeforces
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100+20
typedef long long ll;
ll n,m,k,cost[MAX][MAX],color[MAX],memo[MAX][MAX][MAX];
const ll inf = 1ll<<40;

ll dp(int pos,int ng,int ant){
	if(pos == n) return (ng == k) ? 0 : inf;
	ll &res = memo[pos][ant][ng];
	if(res != -1)return res;
	res = inf;
	if(color[pos] == 0){
		forn(i,1,m+1){
			res = min(res,cost[pos][i]+dp(pos+1,((ant != i) ? ng+1 : ng ),i));
		}
	}else{
		res = min(res,dp(pos+1,((ant != color[pos]) ? ng+1 : ng ),color[pos]));
	}
	return res;
}
int main(){
	forn(i,0,MAX)forn(j,0,MAX)forn(k,0,MAX)memo[i][j][k] = -1;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	forn(i,0,n) cin >> color[i];
	forn(i,0,n)forn(j,1,m+1)cin >> cost[i][j];
	ll res = dp(0,0,m+10);
	if(res == inf) cout << "-1\n";
	else cout << res << "\n";
}
