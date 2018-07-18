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

#define MAX 2000+100
vector<vi> graph;
int t,n,m,seen[MAX],caseno;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cout << "Scenario #" << ++caseno << ":\n";
		cin >> n >> m;
		graph.assign(n,vi());
		forn(i,0,m){
			int u,v; cin >> u >> v;
			u--; v--;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		bool bipartite = true;
		forn(i,0,n+10)seen[i] = -1;
		forn(i,0,n){
			if(seen[i] == -1){
				queue<int> q;
				for(q.push(i); !q.empty(); q.pop()){
					int u = q.front();
					for(auto &v: graph[u]){
						if(seen[v] == -1){
							seen[v] = !seen[u];
							q.push(v);
						}
						if(seen[u] == seen[v]){
							bipartite = false;
							break;
						}
					}
				}
			}
		}
		if(!bipartite)cout << "Suspicious bugs found!\n";
		else cout << "No suspicious bugs found!\n";
	}
}

