#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define MAX 100000+100
vi timer[MAX],coun[MAX];
ll n,m,dist[MAX];
vii graph[MAX];

const ll inf = 1ll<<50;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while(m--){
		int u,v,c; cin >> u >> v >> c; u--; v--;
		graph[u].pb({v,c});
		graph[v].pb({u,c});
	}
	forn(i,0,n){
		cin >> m;
		forn(j,0,m){
			ll tmp; cin >> tmp;
			timer[i].pb(tmp);
			coun[i].pb(1);
		}
		forr(j,m-2,0)if(timer[i][j]+1 == timer[i][j+1])coun[i][j] = coun[i][j+1]+1;
	}
	forn(i,0,n+10)dist[i] = inf;
	priority_queue< ii,vector<ii>,greater<ii> > pq;
	int tmp = (timer[0].empty() || timer[0][0] != 0) ? 0 : coun[0][0];
	dist[0] = tmp; pq.push(ii(tmp,0));

	while(!pq.empty()){
		ii act = pq.top(); pq.pop();
		ll d = act.fi, u = act.se;
		if(d > dist[u])continue;
		for(auto &v: graph[u]){
			ll tmp1 = dist[u]+v.se;
			ll tmp2 = 0;
			auto l = lower_bound(all(timer[v.fi]),tmp1);
			int idx = (l-timer[v.fi].begin());
			if(v.fi != n-1 && !timer[v.fi].empty() && timer[v.fi][idx] == tmp1)tmp2 = coun[v.fi][idx];
			if(tmp1+tmp2 < dist[v.fi]){
				dist[v.fi] = tmp1+tmp2;
				pq.push(ii(dist[v.fi],v.fi));
			}
		}
	}
	ll res = dist[n-1];
	if(res == inf)cout << "-1\n";
	else cout << res << "\n";
	return 0;
}
