#include <bits/stdc++.h>
using namespace std;

#define MAX 100+10

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector< pair<int,ii> > grafo;
vector<vii> grafo2;
vector<int> visitado;
vector<int> padre;

int p[MAX],_rank[MAX],setSize[MAX],numSets;
void makeSet(int s){
	numSets = s;
	for(int i = 1; i <= s; i++){
		p[i] = i; _rank[i] = 0; setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}

int n,r,menor,respuesta;

void dfs(int u,int pdre){
	padre[u] = pdre;
	visitado[u] = 1;
	for(int i = 0; i < grafo2[u].size(); i++)if(visitado[grafo2[u][i].first] == -1)dfs(grafo2[u][i].first,u);
}
void dfs2(int u){
	if(padre[u] == 0) return;
	int tmp = 0;
	for(int i = 0; i < grafo2[u].size(); i++) if(grafo2[u][i].first == padre[u]){tmp = grafo2[u][i].second; break;}
	menor = min(menor,tmp);
	dfs2(padre[u]);
}
int main(){
	int caso = 0;
	while(cin >> n >> r,(n||r)){
		grafo2.assign(n+1,vii());
		visitado.assign(n+1,-1);
		padre.assign(n+1,-1);
		for(int i = 0; i < r; i++){
			int x,y,c; cin >> x >> y >> c;
			grafo.push_back({c,{x,y}});
		}
		int sou,dest,personas;
		cin >> sou >> dest >> personas;
		sort(grafo.begin(),grafo.end());
		makeSet(n);
		for(int i = grafo.size()-1; i >= 0; i--){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				//cout << ac.second.first << " " << ac.second.second << endl;
				unionSet(ac.second.first,ac.second.second);
				grafo2[ac.second.first].push_back({ac.second.second,ac.first});
				grafo2[ac.second.second].push_back({ac.second.first,ac.first});
			}
		}
		dfs(sou,0);
		menor = 1<<30;
		dfs2(dest);
		menor--;
		respuesta = 0;
		while(personas > 0){
			personas -= menor;
			respuesta++;
		}
		cout << "Scenario #" << ++caso << "\n";
		cout << "Minimum Number of Trips = " << respuesta << "\n\n";
		grafo.clear();
	}
}
