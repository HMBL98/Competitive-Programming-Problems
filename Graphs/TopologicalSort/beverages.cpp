#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;

vi visitado,ord,indeg;

map<string,int> mapper;
map<int,string> rmapper;
int n,m;

int main(){
	int caso = 0;
	while(cin >> n){
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		indeg.assign(n+1,0);
		string tmp;
		for(int i = 1; i <= n; i++){
			cin >> tmp;
			mapper[tmp] = i;
			rmapper[i] = tmp;
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			string u,v; cin >> u >> v;
			grafo[mapper[u]].push_back(mapper[v]);
			indeg[mapper[v]]++;
		}
		priority_queue<int, vector<int>, greater<int> > Q;
		for(int i = 1; i <= n; i++) if(indeg[i] == 0) Q.push(i);
		printf("Case #%d: Dilbert should drink beverages in this order:",++caso);
	 	while(!Q.empty()){
            		int u = Q.top(); Q.pop();
            		for(vector<int>::iterator it = grafo[u].begin(); it != grafo[u].end(); it++){
                		indeg[*it]--;
                		if(indeg[*it] == 0) Q.push(*it);
			}
			cout << " " << rmapper[u];

		}
		printf(".\n\n");
		indeg.clear();
		ord.clear();
		mapper.clear();
		rmapper.clear();
	}


}
