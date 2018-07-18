#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
typedef pair<int,int> ii;
vector< pair<int,ii> > graph;
int N,M;

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
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
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int x,y,c; cin >> x >> y >> c; x--; y--;
		graph.push_back({c,{x,y}});
	}
	makeSet(N);
	sort(graph.begin(),graph.end());
	int res = 0;
	for(int i = 0; i < graph.size(); i++){
		pair<int,ii> act = graph[i];
		if(!isSameSet(act.second.first,act.second.second)){
			res += act.first;
			unionSet(act.second.first,act.second.second);
		}
	}
	cout << res << "\n";
	graph.clear();
}

