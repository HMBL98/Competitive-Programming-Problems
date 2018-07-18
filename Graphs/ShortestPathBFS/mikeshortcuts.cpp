//B. Mike and Shortcuts
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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll inf = 1ll<<50;

#define MAX 200000+10
int n;
ll dist[MAX];
vi graph[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,1,n+1){
		int v; cin >> v;
		graph[i].pb(v);
	}
	forn(i,1,n){
		graph[i].pb(i+1);
		graph[i+1].pb(i);
	}
	forn(i,1,n+1)dist[i] = inf;
	queue<int> q; q.push(1); dist[1] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto &v : graph[u]){
			if(dist[v] == inf){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	forn(i,1,n+1)cout << dist[i] << " ";
}
