//C. Checkposts
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;
#define MAX 100000+10

typedef long long ll;
typedef vector<int> vi;
int values[MAX],seen[MAX],low[MAX],num[MAX],n,m,counter;
vi graph[MAX],s;
ll res1,res2 = 1;

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
		vi tmp;
		ll mini = 1LL<<60;
		while(1){
			int v = s.back(); s.pop_back(); seen[v] = 0;
			mini = (mini < values[v]) ? mini : values[v];
			tmp.push_back(v);
			if(u == v)break;
		}
		ll count = 0;
		for(int i = 0; i < tmp.size(); i++){
			if(i) cout << " ";
			cout << tmp[i];
			if(values[tmp[i]] == mini) count++;
		}
		cout << "\n";
		res1 += mini;
		res2 = (res2*count)%MOD;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> values[i];
	cin >> m;
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		if(!num[i]) dfs(i);
	}
	cout << res1 << " " << res2 << "\n";
}
