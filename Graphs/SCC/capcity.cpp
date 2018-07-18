#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
vector<vi> grafo;
vi low,num,visitado,res,S;
int counter;

int dfs(int u){
	low[u] = num[u] = counter++;
	S.push_back(u);
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		int v = grafo[u][i];
		if(num[v] == -1) dfs(v);
		if(visitado[v]) low[u] = min(low[u],low[v]);
	}
	if(low[u] == num[u]){
		cout << "SCC\n";
		while(1){
			int v = S.back(); S.pop_back(); visitado[v] = 0;
			cout << v << "\n";
			res.push_back(v);
			if(u == v)break;
		}
		cout << "\n";
	}
}
int v,e,x,y;

int main(){

	cin >>v >>  e;
	grafo.assign(v+1,vi()); low.assign(v+1,0); num.assign(v+1,-1);visitado.assign(v+1,0);
	counter = 0;
	for(int i = 0; i < e; i++){
		cin >> x >> y;
		grafo[x].push_back(y);
	}
	dfs(4);
	/*cout << res.size() << "\n";
	sort(res.begin(),res.end());
	for(int i = 0; i < res.size(); i++){
		if(i) cout << " ";
		cout << res[i];
	}
	cout << "\n";*/
	res.clear();
}
