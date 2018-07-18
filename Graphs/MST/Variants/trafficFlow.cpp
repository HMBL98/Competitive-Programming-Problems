//10842 - Traffic Flow
#include <bits/stdc++.h>
using namespace std;

#define MAX 100+10

typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0;  i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i),y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}

int t,n,m,caso;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){int u,v,c;cin >> u >> v >> c; grafo.push_back({c,{u,v}});}
		sort(grafo.begin(),grafo.end());
		makeSet(n);
		int menor = 1<<20;
		for(int i = grafo.size()-1; i >= 0; i--){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				menor = min(menor,ac.first);
				unionSet(ac.second.first,ac.second.second);
			}
		}
		cout << "Case #" << ++caso << ": " << menor << "\n";
		grafo.clear();
	}
}
