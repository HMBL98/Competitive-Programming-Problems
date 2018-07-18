//Kruskal (MST): Really Special Subtree
#include <bits/stdc++.h>
using namespace std;

#define MAX 3000+10
typedef pair<int,int> ii;
vector< pair<int,ii> >grafo;
int n,m;

int p[MAX];
int _rank[MAX];
int setSize[MAX];
int numSets;

void makeSet(int _n){
	numSets = _n;
	for(int i = 1; i <= _n; i++){
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
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y,r; cin >> x >> y >> r;
		grafo.push_back({r,{x,y}});
	}
	sort(grafo.begin(),grafo.end());
	makeSet(n);
	long long costo = 0;
	for(int i = 0; i < grafo.size(); i++){
		if(!isSameSet(grafo[i].second.first,grafo[i].second.second)){
			costo += grafo[i].first;
			unionSet(grafo[i].second.first,grafo[i].second.second);
		}
	}
	cout << costo << "\n";
}

