#include <bits/stdc++.h>
using namespace std;

#define MAX 9

typedef pair<int,int> ii;

vector< pair<double,ii> > grafo;
vector<ii> coor;

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));} 
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
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
int n;
int main(){
	while(cin >> n,n){
		for(int i = 0; i < n; i++){
			int x,y; cin >> x >> y;
			coor.push_back({x,y});
		}
		double dist = 0;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				dist = (double)(coor[j].first-coor[i].first)*(coor[j].first-coor[i].first);
				dist += (double)(coor[j].second-coor[i].second)*(coor[j].second-coor[i].second);
				dist = sqrt(dist);
				grafo.push_back({dist,{i,j}});
			}
		}
		makeSet(n);
		double res = 0;
		for(int i = 0; i < grafo.size(); i++){
			pair<double,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				unionSet(ac.second.first,ac.second.second);
				res += ac.first;
			}
		}
		cout << res  << endl;
		coor.clear();
	}
}
