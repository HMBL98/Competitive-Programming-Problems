//10397 - Connect the Campus
#include <bits/stdc++.h>
using namespace std;

#define MAX 750+10
typedef pair<int,int> ii;
vector< pair<double,ii> > grafo;

vector<ii> coor;

int p[MAX],_rank[MAX],setSize[MAX],numSets;
void makeSet(int s){
	numSets = s;
	for(int i = 1; i <= s; i++){
		p[i] = i; _rank[i] = 0; setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
void unionSet(int i,int j){
	int x = findSet(i),y = findSet(j);
	if(x != y){
		numSets--;
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int n,m;
int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++){
			int x,y; cin >> x >> y;
			coor.push_back({x,y});
		}
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				double dist = hypot((coor[i].first-coor[j].first),(coor[i].second-coor[j].second));
				grafo.push_back({dist,{i+1,j+1}});
			}
		}
		cin >> m;
		sort(grafo.begin(),grafo.end());
		makeSet(n+1);
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			unionSet(x,y);
		}
		double res = 0;
		for(int i = 0; i < grafo.size(); i++){
			int x = findSet(grafo[i].second.first);
			int y = findSet(grafo[i].second.second);
			if(x != y){
				unionSet(grafo[i].second.first,grafo[i].second.second);
				res += grafo[i].first;
			}
		}
		printf("%.2f\n",res);
		coor.clear();
		grafo.clear();
	}

}

