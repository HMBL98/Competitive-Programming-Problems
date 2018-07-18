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

#define MAX 100000+10
vi graph[MAX];
int mon[MAX],seen[MAX],deg[MAX],n;
vi res;

int dfs(int u){
	seen[u] = 1;
	for(auto &v: graph[u]){
		if(deg[v] > 1)continue;
		if(seen[v] == 0) seen[u] += dfs(v);
	}
	return seen[u];
}
void print(int u){
	if(deg[u] > 1)return;
	res.push_back(u);
	if(!graph[u].empty())print(graph[u][0]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,1,n+1)cin >> mon[i];
	forn(i,1,n+1){
		int v; cin >> v;
		if(v != 0){
			graph[i].pb(v);
			deg[v]++;
		}
	}
	forn(i,1,n+1){
		if(mon[i] == 1){
			dfs(i);
		}
	}
	int maxi = -1;
	int idx;
	forn(i,1,n+1)
		if(seen[i] > maxi){
			maxi = seen[i];
			idx = i;
		}
	print(idx);
	reverse(res.begin(),res.end());
	cout << maxi << "\n";
	forn(i,0,res.size()){
		if(i)cout << " ";
		cout << res[i];
	}
	cout << "\n";

}
