#include <bits/stdc++.h>
using namespace std;

#define MAX 400+10

typedef pair<int,int> ii;
vector< pair<int,ii> >grafo;

int p[MAX],_rank[MAX],sizeSet[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i; _rank[i] = 0; sizeSet[i] = 1;
	}
}
int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		numSets--;
		int x = findSet(i), y = findSet(j);
		if(_rank[x] < _rank[y]){
			p[y] = x; sizeSet[x] += sizeSet[y];
		}else{
			p[x] = y; sizeSet[y] += sizeSet[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}

int s,c;

int main(){
	while(cin >> s >> c,(s||c)){
		map<string,int> conv;
		for(int i = 0; i < s; i++){
			string tmp;cin >> tmp;
			conv[tmp] = i;
		}
		for(int i = 0; i < c; i++){
			string x,y; int r;
			cin >> x >> y >> r;
			int u = conv[x], v = conv[y];
			grafo.push_back({r,{u,v}});
		}
		string tmp; cin >> tmp;
		sort(grafo.begin(),grafo.end());
		makeSet(s);
		long long costo = 0;
		for(int i = 0; i < c; i++){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				costo += ac.first;
				unionSet(ac.second.first,ac.second.second);
			}
		}
		if(numSets != 1)cout << "Impossible\n";
		else cout << costo << "\n";
		grafo.clear();
	}
}

