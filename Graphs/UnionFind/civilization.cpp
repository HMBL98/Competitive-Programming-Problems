#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MX 300000+10
int n,m,q,p[MX],_rank[MX],setsize[MX],seen[MX],diameter[MX],numsets;
vi graph[MX];
const int inf = 1<<20;

void init(){
	numsets = n;
	forn(i,0,n){
		p[i] = i;
		setsize[i] = 1;
		_rank[i] = 0;
		diameter[i] = 0;
		seen[i] = 0;
	}
}
int findset(int i){return (p[i] == i) ? p[i] : (p[i] = findset(p[i]));}
void unionset(int x,int y){
	if(_rank[x] > _rank[y]){
		p[y] = x; setsize[x] += setsize[y];
		diameter[x] = max(diameter[x],max(diameter[y],(diameter[x]+1)/2+(diameter[y]+1)/2 +1));
	}else{
		p[x] = y; setsize[y] += setsize[x];
		if(_rank[x] == _rank[y]) _rank[y]++;
		diameter[y] = max(diameter[y],max(diameter[x],(diameter[x]+1)/2+(diameter[y]+1)/2 +1));
	}
}
int maxi,maxiid;
int dfs(int u,int par,int di){
	if(di > maxi){
		maxi = di;
		maxiid = u;
	}
	for(auto &v : graph[u]){
		if(v != par)dfs(v,u,di+1);
	}
}
int getdiam(int src){
	maxi = 0,maxiid = -1;
	dfs(src,-1,0);
	if(maxiid == -1)return 0;
	maxi = 0;
	dfs(maxiid,-1,0);
	return maxi;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	init();
	forn(i,0,m){
		int u,v; cin >> u >> v; u--; v--;
		unionset(findset(u),findset(v));
		graph[u].pb(v);
		graph[v].pb(u);
	}
	forn(i,0,n){
		int u = findset(i);
		if(!seen[u]){
			diameter[u] = getdiam(i);
			seen[u] = 1;
		}
	}
	forn(i,0,q){
		int opc,u,v; cin >> opc;
		if(opc == 1){
			cin >> v; v--;
			cout << diameter[findset(v)] << "\n";
		}else{
			cin >> u >> v; u--; v--;
			int x = findset(u),y = findset(v);
			if(x != y)unionset(x,y);
		}
	}
	return 0;
}
