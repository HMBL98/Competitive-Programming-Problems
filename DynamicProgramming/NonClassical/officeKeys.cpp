#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 1000+10
#define MAXM 2000+10
ll n,m,ori,p[MAXN],k[MAXM],memo[MAXN][MAXM];
const ll inf = 1ll<<50;

ll dp(int pos1,int pos2){
	if(pos1 == n)return 0;
	if(pos2 == m)return inf;
	ll &res = memo[pos1][pos2];
	if(res != -1)return res;
	res = inf;
	res = min(res,max(  abs(k[pos2]-p[pos1])+abs(ori-k[pos2]) , dp(pos1+1,pos2+1)     )    );
	res = min(res,dp(pos1,pos2+1));
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> ori;
	forn(i,0,n)cin >> p[i];
	forn(i,0,m)cin >> k[i];
	sort(p,p+n);
	sort(k,k+m);
	forn(i,0,n+10)forn(j,0,m+10)memo[i][j] = -1;
	cout << dp(0,0) << "\n";
}
