//1216 - The Bug Sensor Problem
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vector< pair<double,ii> > grafo;

vi p,_rank,sizeSet;
int numSets;


void makeSet(int s){
	numSets = s;
	p.clear(); _rank.clear(); sizeSet.clear();
	for(int i = 0; i < s; i++){
		p.push_back(i);
		_rank.push_back(0);
		sizeSet.push_back(1);
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		numSets--;
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; sizeSet[x] += sizeSet[y];
		}else{
			p[x] = y; sizeSet[y] += sizeSet[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int w,n;


int main(){
	cin >> w;
	while(w--){
		cin >> n;
		int x,y;
		vector< pair<int,int> > cor;
		while(cin >> x){
			if(x == -1) break;
			cin >> y;
			cor.push_back({x,y});
		}
		for(int i = 0; i < cor.size(); i++){
			for(int j = i+1; j < cor.size(); j++){
				double uno = (double)(cor[i].first-cor[j].first);
				uno *= uno;
				double dos = (double)(cor[i].second-cor[j].second);
				dos *= dos;
				double distancia = sqrt(uno+dos);
				grafo.push_back({distancia,{i,j}});
			}
		}
		sort(grafo.begin(),grafo.end());
		makeSet(cor.size());
		vector<double> aristas;
		for(int i = 0; i < grafo.size(); i++){
			pair<double,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				aristas.push_back(ac.first);
				unionSet(ac.second.first,ac.second.second);
			}
		}
		//for(int i = 0; i < aristas.size(); i++) cout << aristas[i] << endl;
		n--;
		if(n < aristas.size()) cout << ceil(aristas[aristas.size()-1-n]) << "\n";
		else cout << ceil(aristas[0]) << "\n";
		grafo.clear();
	}
}
