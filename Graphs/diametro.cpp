#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 200000+10

typedef vector<int> vi;
vector<vi> grafo(MAX);
int n,visitados[MAX];

int max1,max2;
int idx1,idx2;
void dfs(int n,int capa,bool uno){
	visitados[n] = capa;
	if(uno && capa > max1) max1 = capa, idx1 = n;
	if(!uno && capa > max2) max2 = capa, idx2 = n;

	for(int i = 0; i < (int)grafo[n].size(); i++)
		if(visitados[grafo[n][i]] == -1) dfs(grafo[n][i],capa+1,uno);
}

int main(){
	optimizar_io;
	cin >> n;
	for(int i = 1; i <= n+1; i++) visitados[i] = -1;
	for(int i = 1; i < n; i++){
		int x,y; cin >> x >> y;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
	dfs(1,0,true);
	for(int i = 1; i <= n+1; i++) visitados[i] = -1;
	dfs(idx1,0,false);
	cout << max2 << endl;
}
