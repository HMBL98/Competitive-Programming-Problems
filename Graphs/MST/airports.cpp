#include <bits/stdc++.h>
using namespace std;

#define MAX 10000+10
typedef long long ll;
typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i; _rank[i] = 0; setSize[i] = 1;
	}
}
int findSet(int i){return (i == p[i]) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		numSets--;
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}

int t,n,m,a;
int main(){
	cin >> t;
	int caso = 0;
	while(t--){
		cin >> n >> m >> a;
		for(int i = 0; i < m; i++){
			int x,y,r; cin >> x >> y >> r;
			x--,y--;
			grafo.push_back({r,{x,y}});
		}
		sort(grafo.begin(),grafo.end());
		makeSet(n);
		ll res = a*(long long)n;
		ll aero = n;
		ll tomadas = 0;
		for(int i = 0; i < m; i++){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				tomadas += ac.first;
				unionSet(ac.second.first,ac.second.second);
				if(tomadas+numSets*a < res){
					res = tomadas+numSets*a;
					aero = numSets;
				}

			}
		}
		if(numSets == 1) res = min(res,tomadas+a);
		cout << "Case #" << ++caso << ": " << res << " " << aero << "\n"; 
		grafo.clear();
	}

}
