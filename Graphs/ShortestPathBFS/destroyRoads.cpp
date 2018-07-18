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
typedef vector<ll> vi;
typedef vector<ii> vii;

#define MAX 3000+10
int n,m,p[MAX],s1,t1,l1,s2,t2,l2;
ll dist[MAX];
vi graph[MAX];

const ll inf = 1ll<<50;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,0,m){
		int u,v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;

	set<ii> diff;
	function<void(int)> print = [&](int u){
		if(p[u] == u)return;
		else{
			int p1 = min(u,p[u]);
			int p2 = max(u,p[u]);
			diff.insert({p1,p2});
			print(p[u]);
		}
	};
	function<bool(int)> bfs = [&](int opc){
		int src = (opc == 1) ? s1 : s2;
		int dest = (opc == 1) ? t1 : t2;
		int limit = (opc == 1) ? l1 : l2;
		forn(i,0,n+10){
			dist[i] = inf;
			p[i] = 0;
		}
		queue<int> q; dist[src] = 0; p[src] = src;
		for(q.push(src); !q.empty(); q.pop()){
			int u = q.front();
			for(auto &v: graph[u]){
				if(dist[v] == inf){
					dist[v] = dist[u]+1;
					p[v] = u;
					q.push(v);
				}
			}
		}
		print(dest);
		if(dist[dest] > limit)return false;
		else return true;
	};
	if( !bfs(1) || !bfs(2))cout << "-1\n";
	else cout << m-diff.size() << "\n";
	return 0;
}
