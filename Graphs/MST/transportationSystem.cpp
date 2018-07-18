//11228 - Transportation system.
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000+10
typedef pair<int,int> ii;
typedef vector<int> vi;
vector< pair<double,ii> > grafo;
vector<vi> grafo2;
vi visitados;
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

int t,n,r;

void dfs(int u){
	visitados[u] = 1;
	for(int i = 0; i < grafo2[u].size(); i++)
		if(visitados[grafo2[u][i]] == -1) dfs(grafo2[u][i]);
}
int main(){
	optimizar_io;
	cin >> t;
	int caso = 0;
	while(t--){
		cin >> n >> r;
		makeSet(n);
		grafo.clear();
		grafo2.clear();
		visitados.assign(n,-1);
		vector<ii> coor(n,ii());
		grafo2.assign(n,vi());
		for(int i = 0; i < n; i++) cin >> coor[i].first >> coor[i].second;
		for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
			double distancia = hypot((coor[j].first-coor[i].first),(coor[j].second-coor[i].second));
			//cout << distancia << endl;
			grafo.push_back({distancia,{i,j}});
		}
		sort(grafo.begin(),grafo.end());
		double res1 = 0,res2 = 0;
		int res = 1;
		for(int i = 0; i < grafo.size(); i++){
			pair<double,ii> actual = grafo[i];
			if(!isSameSet(actual.second.first,actual.second.second)){
				if(actual.first <= r){
					res1 += actual.first;
					grafo2[actual.second.first].push_back(actual.second.second);
					grafo2[actual.second.second].push_back(actual.second.first);

				}else{
					res++;
					res2 += actual.first;
				}
				unionSet(actual.second.first,actual.second.second);
			}
		}
		//int res = 0;
		//for(int i = 0; i < n; i++)if(visitados[i] == -1) res++,dfs(i);
		cout << "Case #" << ++caso << ": " << res << " " << round(res1) << " " << round(res2) << '\n';
	}
}

