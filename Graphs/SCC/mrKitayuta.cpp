//D. Mr. Kitayuta's Technology codeforces
#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10
typedef vector<int> vi;
int seen[MAX],low[MAX],num[MAX],counter,n,m,res,scc;
vi graph[MAX],s;

void dfs(int u){
	seen[u] = 1;
	low[u] = num[u] = ++counter;
	s.push_back(u);
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(!num[v]) dfs(v);
		if(seen[v]) low[u] = min(low[u],low[v]);
	}
	if(low[u] == num[u]){
		int count = 0;
		vi tmp;
		while(1){
			int v = s.back(); s.pop_back(); seen[v] = 0;
			tmp.push_back();
			count++;
			if(u == v)break;
		}
		if(count > 1) res += count;
		scc++;
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
	}
	for(int i = 1; i <= n; i++) if(!num[i]) dfs(i);
	res += scc-1;
	cout << res << "\n";
}
