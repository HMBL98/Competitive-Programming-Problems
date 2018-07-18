//11631 - Dark roads
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 200000+10
#define MAX_N 200000+10
typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;

int p[MAX];
int _rank[MAX];
int sizeSet[MAX];
int numSets;

void makeSet(int _size){
	numSets = _size;
	for(int i = 0; i < _size; i++){
		p[i] = i;
		_rank[i] = 0;
		sizeSet[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : findSet(p[i]);}
bool isSameSet(int i,int j){return (findSet(i) == findSet(j));}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; sizeSet[x] += sizeSet[y];
		}else{
			p[x] = y; sizeSet[y] += sizeSet[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int m,n;
int main(){
	optimizar_io;
	while(cin >> m >> n,(m||n)){
		long long total = 0;
		for(int i = 0; i < n; i++){
			int x,y,r; cin >> x >> y >> r;
			total += r;
			grafo.push_back({r,{x,y}});
		}
		sort(grafo.begin(),grafo.end());
		makeSet(m);
		long long costo = 0;
		for(int i = 0; i < n; i++){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				unionSet(ac.second.first,ac.second.second);
				costo += ac.first;
			}
		}
		cout << total-costo << endl;
		grafo.clear();
	}
}
