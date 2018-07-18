//10731 - Test
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;

vi low,num,visitado,s; int counter;

vector<vi> componentes;


void dfs(int u){
	low[u] = num[u] = counter++;
	s.push_back(u);
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(num[grafo[u][i]] == -1) dfs(grafo[u][i]);
		if(visitado[grafo[u][i]]) low[u] = min(low[u],low[grafo[u][i]]);
	}
	if(low[u] == num[u]){
		vector<int> tmp;
		while(1){
			int v = s.back(); s.pop_back(), visitado[v] = 0;
			tmp.push_back(v);
			//cout << (char)v+'A' << " ";
			if(u == v)break;
		}
		//cout << endl;
		sort(tmp.begin(),tmp.end());
		componentes[tmp[0]] = tmp;
	}
}


char letras[5],l;

int n;


int main(){
	int caso = 0;
	while(cin >> n,n){
		if(caso++) cout << "\n";
		grafo.assign(27,vi()); low.assign(27,0); num.assign(27,-1); visitado.assign(27,-1);
		componentes.assign(27,vi());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++)cin >> letras[j];
			cin >> l;
			for(int j = 0; j < 5; j++) if(l != letras[j]) grafo[l-'A'].push_back(letras[j]-'A');
		}
		for(int i = 0; i < 27; i++){
			if(!grafo[i].empty() && visitado[i] == -1) dfs(i);
		}
		for(int i = 0; i < 27; i++){
			if(!componentes[i].empty()){
				for(int j = 0; j < componentes[i].size(); j++){
					if(j) cout << " ";
					cout << (char)(componentes[i][j]+'A');
				}
				cout << "\n";
			}
		}
	}
}
