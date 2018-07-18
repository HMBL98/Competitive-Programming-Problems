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
ll n,m,_rank[MAX],p[MAX],setSize[MAX],val[MAX];
vector< pair<ll,ii> > edges;

void init(int s){
	forn(i,0,s){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
void unionSet(int x,int y){
	if(_rank[x] > _rank[y]){
		p[y] = x; setSize[x] += setSize[y];
	}else{
		p[x] = y; setSize[y] += setSize[x];
		if(_rank[x] == _rank[y]) _rank[y]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,0,n)cin >> val[i];
	forn(i,0,m){
		int u,v; cin >> u >> v;
		u--; v--;
		edges.pb({min(val[u],val[v]),{u,v}});
	}
	init(n);
	sort(edges.begin(),edges.end(),[](pair<ll,ii> a,pair<ll,ii> b){
		return a.fi > b.fi;
	});
	double res = 0;
	double den = n*(n-1);
	for(auto &e : edges){
		int x = findSet(e.se.fi),y = findSet(e.se.se);
		if(x != y){
			double s1 = setSize[x];
			double s2 = setSize[y];
			double num = double(s1)*double(s2); num *= double(e.fi);
			num  *= 2;
			res +=  num/den;
			unionSet(x,y);
		}
	}
	cout << setprecision(6) << fixed <<  res << "\n";
}
