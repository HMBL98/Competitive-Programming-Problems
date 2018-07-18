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

#define MAX 100000+10
int n,p[MAX],_rank[MAX],setSize[MAX];
vector< pair<int,ii> > edges;
void init(int s){
	forn(i,0,n){
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
		if(_rank[x] == _rank[y])_rank[y]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,0,n)forn(j,i,n)if(i != j)edges.pb({int(i^j),{i,j}});
	init(n);
	sort(all(edges));
	//for(auto &e : edges)cout << e.se.fi << " " << e.se.se << "--->" << e.fi << "\n";
	int res = 0;
	cout << "Ans :D\n";
	for(auto &e : edges){
		int x = findSet(e.se.fi), y = findSet(e.se.se);
		if(x != y){
			cout << e.se.fi << " " << e.se.se << "--->" << e.fi << "\n";
			res += e.fi;
			unionSet(x,y);
		}
	}
	cout << res << "\n";
}
