//3988 - IP-TV
#include <bits/stdc++.h>
using namespace std;

#define MAX 2000+10

typedef pair<int,int> ii;
vector< pair<double,ii> > grafo;

map<string,int> mapper;
int t,n,m,idx;

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 1; i <= s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i),y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int caso;
int main(){
	cin >> t;
	while(t--){
		if(caso++)cout << "\n";
		cin >> n >> m;
		idx = 1;
		for(int i = 0; i < m; i++){
			int u,v,c;
			string s1,s2; cin >> s1 >> s2 >> c;
			u = mapper[s1],v = mapper[s2];
			if(!u){
				u = idx++;
				mapper[s1] = u;
			}
			if(!v){
				v = idx++;
				mapper[s2] = v;
			}

			grafo.push_back({c,{u,v}});
		}
		sort(grafo.begin(),grafo.end());
		makeSet(n+1);
		int res = 0;
		for(int i = 0; i < grafo.size(); i++){
			pair<double,ii> ac =grafo[i];
			if(!isSameSet(ac.second.first,ac.second.second)){
				unionSet(ac.second.first,ac.second.second);
				res += ac.first;
			}
		}
		cout << res << "\n";
		grafo.clear();
		mapper.clear();
	}
}
