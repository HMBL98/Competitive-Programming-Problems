#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define fi first;
#define se second;
#define pb push_back
#define MAXV 50000
#define MAXK 500

typedef vector<int> vi;

int n,k,seen[MAXV][MAXK];
vi graph[MAXV];

int dfs(int u,int dist){
	if(dist > 5)return 0;
	seen[u][dist] = 1;
	int res = 0;
	for(auto &v: graph[u]){
		if(!seen[v][dist+1]){
			res += dfs(v,dist+1);
		}
		if(!seen[v][1]){
			res += dfs(v,1);
		}
		if(dist+1 == k)res++;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	forn(i,0,n-1){
		int u,v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	cout << dfs(1,0) << "\n";
}
