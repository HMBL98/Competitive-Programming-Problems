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

#define MAXV 100000+10
#define LOGV 30
int n,m,seen[MAXV],depth[MAXV],size[MAXV],parent[LOGV][MAXV];
vi graph[MAXV];

int dfs(int u){
	seen[u] = 1;
	size[u] = 1;
	for(auto &v : graph[u]){
		if(!seen[v]){
			parent[0][v] = u;
			depth[v] = depth[u]+1;
			size[u] += dfs(v);
		}
	}
	return size[u];
}
void pre(){
	dfs(0);
	for(int i = 1; i < LOGV; i++){
		for(int j = 0; j < n; j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
}
int getParent(int u,int k){
	for(int i = 0; i < LOGV; i++){
		if(k&1){
			u = parent[i][u];
		}
		k >>= 1;
	}
	return u;
}
int lca(int u,int v){
	if(depth[u] > depth[v]){
		u = getParent(u,depth[u]-depth[v]);
	}else if(depth[v] > depth[u]){
		v = getParent(v,depth[v]-depth[u]);
	}
	if(u == v)return u;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,0,n-1){
		int u,v; cin >> u >> v;
		u--; v--;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	pre();
	cin >> m;
	forn(i,0,m){
		int u,v; cin >> u >> v; u--; v--;
		//cout << lca(u,v)+1 << "\n";
		if(u == v){
			cout << n-1 << "\n";
			continue;
		}
		int dist = depth[u]+depth[v]-2*depth[lca(u,v)];
		if(dist%2 != 0){
			cout << "0\n";
			continue;
		}
		if(depth[u] == depth[v]){
			cout << n-(size[lca(u,v)]-1) << "\n";
		}else{
			int a = (depth[u] > depth[v]) ? u : v;
			cout << size[getParent(a,dist/2)]-size[getParent(a,dist/2-1)] << "\n";
		}
	}
}
