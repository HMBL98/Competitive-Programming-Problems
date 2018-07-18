#include <bits/stdc++.h>
using namespace std;

#define MAX 100+1
typedef vector<int> vi;
vector<vi> grafo;
int visitados[MAX];

int n;

void dfs(int v){
	for(int i = 0; i < (int)grafo[v].size(); i++){
		if(visitados[grafo[v][i]] == -1){
			visitados[grafo[v][i]] = 1;
			dfs(grafo[v][i]);
		}
	}
}
int main(){
	while(cin >> n && n){
		grafo.assign(MAX,vi());
		int p,q;
		while(cin >> p && p){
			while(cin >> q && q){
				grafo[p].push_back(q);
			}
		}
		int queries,source;
		vector<int> vertices;
		cin >> queries;
		while(queries--){
			cin >> source;
			for(int i = 0; i <= n; i++) visitados[i] = -1;
			dfs(source);
			for(int i = 1; i <= n; i++) if(visitados[i] == -1) vertices.push_back(i);
			cout << vertices.size();
			for(int i = 0; i < vertices.size(); i++){
				cout << " " << vertices[i];
			}
			cout << endl;
			vertices.clear();
		}
	}
}
