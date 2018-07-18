//10147 - Highways
#include <bits/stdc++.h>
using namespace std;

#define MAX 750+10

typedef pair<int,int>  ii;
vector< pair<double,ii> > grafo;
vector<ii> coor;
int t,n,m;

int p[MAX],_rank[MAX],sizeSet[MAX],numSets;
void makeSet(int s){
	numSets = s;
	for(int i = 1; i <= s; i++){
		p[i] = i;
		_rank[i] = 0;
		sizeSet[i] = 1;
	}
}
int findSet(int i){return (p[i]==i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	int x = findSet(i),y = findSet(j);
	if(x != y){
		numSets--;
		if(_rank[x] > _rank[y]){
			p[y] = x; sizeSet[x] += sizeSet[y];
		}else{
			p[x] = y; sizeSet[y] += sizeSet[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int caso;
int main(){
	cin >> t;
	while(t--){
		if(caso++) cout << "\n";
		cin >> n;
		coor.assign(n,ii());
		for(int i = 0; i < n; i++)cin >> coor[i].first >> coor[i].second;
		makeSet(n);
		cin >> m;
		for(int i = 0; i < m; i++){
			int x,y;
			cin >> x >> y;
			unionSet(x,y);
		}
		if(numSets == 1){
			cout << "No new highways need\n";
		}else{
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					double dist = hypot(coor[i].first-coor[j].first,coor[i].second-coor[j].second);
					//cout << i+1 << " " << j+1 << " " << dist << "\n";	
					grafo.push_back({dist,{i+1,j+1}});
				}
			}
			sort(grafo.begin(),grafo.end());
			for(int i = 0; i < grafo.size(); i++){
				pair<double,ii> ac = grafo[i];
				if(!isSameSet(ac.second.first,ac.second.second)){
					cout << ac.second.first << " " << ac.second.second << "\n";
					unionSet(ac.second.first,ac.second.second);
				}
			}
		}
		grafo.clear();

	}
}
