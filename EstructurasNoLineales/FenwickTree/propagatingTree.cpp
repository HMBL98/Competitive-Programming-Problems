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

#define MAX 200000+10
int n,m,counter,in[MAX],out[MAX],val[MAX],sig[MAX],bit[2*MAX];
vi graph[MAX];

void dfs(int u,int p,int s){
	in[u] = ++counter;
	sig[u] = s;
	for(auto &v : graph[u])if(v != p)dfs(v,u,-s);
	out[u] = ++counter;
}
int query(int idx){
	int sum = 0;
	while(idx){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum;
}
void update(int idx,int v){
	//cout << idx << " " << v << "\n";
	while(idx < 2*MAX){
		bit[idx] += v;
		idx += idx&-idx;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,1,n+1)cin >> val[i];
	forn(i,0,n-1){
		int u,v; cin >> u >> v; 
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfs(1,-1,1);
	//forn(i,1,n+1)cout << i << " " << in[i] << " " << out[i] << "\n";
	while(m--){
		int opc; cin >> opc;
		if(opc == 1){
			int u,c; cin >> u >> c;
			update(in[u],c*sig[u]);
			update(out[u]+1,-c*sig[u]);
		}else{
			int u; cin >> u;
			cout << val[u]+sig[u]*query(in[u]) << "\n";
		}
	}
}
