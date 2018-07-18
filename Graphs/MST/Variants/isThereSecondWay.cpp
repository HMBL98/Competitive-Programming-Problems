//10462 - Is There A Second Way Left?
#include <bits/stdc++.h>
using namespace std;

#define MAX 100+10

typedef pair<int,int> ii;
vector< pair<int,ii> > grafo;
vector< pair<int,ii> > grafo2;
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


int t,v,e,caso;

int main(){
	cin >> t;
	while(t--){
		cin >> v >> e;
		int x,y,c;
		for(int i = 0; i < e; i++){
			cin >> x >> y >> c; x--; y--; 
			if(x < y) grafo.push_back({c,{x,y}});
			else      grafo.push_back({c,{y,x}});
			//grafo.push_back({c,{x,y}});
		}
		sort(grafo.begin(),grafo.end());
		makeSet(v);

		for(int i = 0; i < grafo.size(); i++){
			pair<int,ii> ac = grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				grafo2.push_back({ac.first,{ac.second.first,ac.second.second}});
				unionSet(ac.second.first,ac.second.second);
			}
		}
		cout << "Case #" << ++caso << " : ";
		if(numSets != 1)cout << "No way\n";
		else{
			int mini = 1<<20;
			int tmp = 0;
			for(int i = 0; i < grafo2.size(); i++){
				makeSet(v);
				tmp = 0;
				for(int j = 0; j < grafo.size(); j++){
					if(grafo2[i] != grafo[j] || (j < grafo.size()-1 && grafo[j] == grafo[j+1])){
						pair<int,ii> ac = grafo[j];
						if(!isSameSet(ac.second.first,ac.second.second)){
							tmp += ac.first; unionSet(ac.second.first,ac.second.second);
						}
					}
				}
				if(numSets == 1) mini = min(mini,tmp);
			}
			if(mini != 1<<20 && e != 0) cout << mini << "\n";
			else cout << "No second way\n";
		}
		grafo.clear();
		grafo2.clear();
	}
}
