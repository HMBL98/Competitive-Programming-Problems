#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 50
int n,m,p[MAX],_rank[MAX],setSize[MAX],numSets;
vi teams[MAX];

void makeSet(int s){
	numSets = s;
	forn(i,0,s){
		p[i] = i;
		setSize[i] = 1;
		_rank[i] = 0;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
void unionSet(int i,int j){
	int x = findSet(i),y = findSet(j);
	if(x != y){
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	makeSet(n);
	while(m--){
		int u,v; cin >> u >> v;
		u--; v--;
		unionSet(u,v);
	}
	vector<int> ocu(n,0);
	int idx = 0;
	bool status = true;
	vii ord(n);
	forn(i,0,n) ord[i] = {setSize[findSet(i)],i};
	sort(ord.begin(),ord.end(),[](ii a,ii b){
		return a.first > b.first;
	});
	forn(k,0,n){
		int i = ord[k].se;
		if(setSize[findSet(i)] > 3){
			status = false;
			break;
		}
		if(!ocu[i]){
			teams[idx].pb(i+1);
			int c1 = 3-setSize[findSet(i)];
			ocu[i] = 1;
			forn(j,0,n){
				if(findSet(i) == findSet(j) && !ocu[j]){
					teams[idx].pb(j+1);
					ocu[j] = 1;
				}else{
					if(c1 && !ocu[j] && setSize[findSet(j)] == 1){
						ocu[j] = 1;
						teams[idx].pb(j+1);
						c1--;
					}
				}
			}
			if(teams[idx].size() != 3){
				status = false;
				break;
			}
			idx++;
		}
	}
	if(!status)cout << "-1\n";
	else{
		forn(i,0,n/3){
			for(auto &x : teams[i])cout << x << " ";
			cout << "\n";
		}
	}

}
