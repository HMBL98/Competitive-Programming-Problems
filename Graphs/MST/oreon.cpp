#include <bits/stdc++.h>
using namespace std;

//#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 30
typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;
int t,n;

int p[MAX];
int _rank[MAX];
int setSize[MAX];
int numSets;

//Método de inicialización
void makeSet(int n){
	numSets = n;
	for(int i = 0; i < n; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
//Método para encontrar la raiz del vértice actual X
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
//Método para unir 2 componentes conexas usando sus alturas (rangos)
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		numSets--;
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){ p[y] = x; setSize[x] += setSize[y];}
		else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int sizeOfSet(int i){ return setSize[findSet(i)];}


int main(){
	int caso = 0;
	scanf("%d",&t);
	while(t--){
		makeSet(30);
		scanf("%d",&n);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
			int valor; char cha;
			scanf("%d%c",&valor,&cha);
			if(j > i && valor != 0) grafo.push_back({valor,{i,j}});
		}
		sort(grafo.begin(),grafo.end());
		int costo = 0;
		cout << "Case " << ++caso << ":" << '\n';
		for(int i = 0; i < grafo.size(); i++){
			pair<int,ii> actual = grafo[i];
			if(!isSameSet(actual.second.first,actual.second.second)){
				costo += actual.first;
				cout << (char)(actual.second.first+'A') << "-" << (char)(actual.second.second+'A') << " " << actual.first << '\n';
				unionSet(actual.second.first,actual.second.second);

			}
		}
		grafo.clear();
	}
}

