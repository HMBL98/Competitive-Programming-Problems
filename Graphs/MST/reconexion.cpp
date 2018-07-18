#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100000+10
typedef pair<int,int> ii;
vector< pair<int,ii> >grafo;
int n,m,a;

int p[MAX];
int _rank[MAX];
int setSize[MAX];
int numSets;

void makeSet(int _n){
	numSets = _n;
	for(int i = 0; i < _n; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
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
int sizeOfSet(int i){ return setSize[findSet(i)];}
int main(){
	optimizar_io;
	cin >> n >> m >> a;
	for(int i = 0; i < m; i++){
		int x,y,r; cin >> x >> y >> r;
		grafo.push_back({r,{x,y}});
	}
	sort(grafo.begin(),grafo.end());
	makeSet(n);
	long long res = n*(long long)a;
	long long tomadas = 0;
	for(int i = 0; i < m; i++){
		pair<int,ii> ac = grafo[i];
		if(!isSameSet(ac.second.first,ac.second.second)){
			long long uno = tomadas+ac.first+((numSets-1)*a);
                        long long dos = tomadas+numSets*a;
                        res = min(res,uno); res = min(res,dos);
                        tomadas += ac.first;
                       	unionSet(ac.second.first,ac.second.second);
		}
	}
	if(numSets == 1) res = min(res, tomadas);
	cout << res << endl;
}
