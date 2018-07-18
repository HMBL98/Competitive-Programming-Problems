//11857 - Driving Range
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
vector< pair<int,ii> > grafo;

vi p,_rank,sizeSet;
int numSets;

void makeSet(int s){
	numSets = s;
	p.clear();_rank.clear();sizeSet.clear();
	for(int i = 0; i < s; i++){
		p.push_back(i);
		_rank.push_back(0);
		sizeSet.push_back(1);
	}
}
int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
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

int n,m;

int main(){
	while(cin >> n >> m,(n||m)){
		for(int i = 0; i < m; i++){
			int x,y,r; cin >> x >> y >> r;
			grafo.push_back({r,{x,y}});
		}
		sort(grafo.begin(),grafo.end());
		makeSet(n);
		int maximo = -1;
		for(int i = 0; i < m; i++){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				maximo = max(maximo,ac.first);
				unionSet(ac.second.first,ac.second.second);
			}
		}
		if(maximo == -1 || numSets != 1)cout << "IMPOSSIBLE" << endl;
		else cout << maximo << endl;
		grafo.clear();
	}
}

