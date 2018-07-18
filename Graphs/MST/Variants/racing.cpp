#include <bits/stdc++.h>
using namespace std;

#define MAX 10000+10
typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;

int p[MAX],_rank[MAX],sizeSet[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		sizeSet[i] = 1;
	}
}
int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i),y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; sizeSet[x] += sizeSet[y];
		}else{
			p[x] = y; sizeSet[y] += sizeSet[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
		
	}
}

int t,n,m,x,y,c,total,res;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m; total = 0;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> c;
			x--; y--;
			grafo.push_back({c,{x,y}});
			total += c;
		}
		makeSet(n);
		sort(grafo.begin(),grafo.end());
		res = 0;
		for(int i = grafo.size()-1; i >= 0; i--){
			pair<int,ii> act = grafo[i];
			if(!isSameSet(act.second.first,act.second.second)){
				res += act.first;
				unionSet(act.second.first,act.second.second);
			}
		}
		cout << total-res << "\n";
		grafo.clear();
	}
	cin >> t;
}
