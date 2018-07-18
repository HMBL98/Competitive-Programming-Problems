//arboles chistosos omegaup
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 200000+10

typedef vector<int> vi;
int n,m,values[MAXN],seen[MAXN],in[MAXN],out[MAXN],signo[MAXN],counter;
int bit[2*MAXN];
vi graph[MAXN];

void dfs(int u,int sig){
	seen[u] = 1;
	signo[u] = sig;
	in[u] = ++counter;
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(!seen[v]) dfs(v,-sig);
	}
	out[u] = ++counter;
}
int getSum(int idx){
	int sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= idx&(-idx);
	}
	return sum;
}
int update(int idx,int val){
	while(idx < 2*(n+1)){
		bit[idx] += val;
		idx += idx&(-idx);
	}
}
int main(){
	optimizar_io;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> values[i];
	for(int i = 1; i < n; i++){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,1);
	while(m--){
		int opc; cin >> opc;
		if(opc == 1){
			int u,c; cin >> u >> c;
			update(in[u],c*signo[u]);
			update(out[u]+1,-c*signo[u]);
		}else{
			int u; cin >> u;
			cout << values[u]+getSum(in[u])*signo[u] << "\n";
		}
	}

}
