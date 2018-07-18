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

#define MAXN 1000+10
#define MAXK 2000+10

ll per[MAXN],key[MAXK],n,k,p;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> p;
	forn(i,0,n)cin >> per[i];
	forn(i,0,k)cin >> key[i];

	vector<int> caj;
	forn(i,0,n){
		set<int> diff;
		forn(j,0,k){
			ll dist = abs(key[j]-per[i])+abs(key[j]-p);
			cout << i << " " << j << " " << dist << "\n";
			diff.insert(dist);
		}
		for(auto &d : diff)caj.pb(d);
	}
	ll ini = 0, fin = 1ll<<50;
	while(ini < fin){
		ll mit = (ini+fin)>>1;
		ll count = 0;
		for(auto &x : caj) count += (mit/x) ? 1 : 0;
		if(count >= n)fin = mit;
		else ini = mit+1;
	}
	cout << ini << "\n";

}
