#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000+10

typedef pair<int,int> ii;
typedef vector<int> vi;
vector< pair<double,ii> > grafo;
vector<ii> coor;

int p[MAX];
int _rank[MAX];
int setSize[MAX];
int numSets;

void makeSet(int n){
	numSets = n;
	for(int i = 0; i < n; i++){
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

int n;

int main(){
	optimizar_io;
	while(cin >> n,n){
		makeSet(n);
		coor.assign(n,ii());
		for(int i = 0; i < n; i++) cin >> coor[i].first >> coor[i].second;
		for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
			double distancia = hypot((coor[j].first-coor[i].first),(coor[j].second-coor[i].second));
			//cout << distancia << endl;
			grafo.push_back({distancia,{i,j}});
		}
		sort(grafo.begin(),grafo.end());
		double res = 0;
		for(int i = 0; i < grafo.size(); i++){
			pair<double,ii> actual = grafo[i];
			if(!isSameSet(actual.second.first,actual.second.second)){
				res += actual.first;
				unionSet(actual.second.first,actual.second.second);
			}
		}
		printf("%.2f\n",res);
		grafo.clear();
	}
}

