#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;

vi low,num,visitado,s;
map<string,int> mapper;
int res,counter;

void dfs(int u){
	low[u] = num[u] = counter++;
	s.push_back(u);
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(num[grafo[u][i]] == -1) dfs(grafo[u][i]);
		if(visitado[grafo[u][i]])low[u] = min(low[u],low[grafo[u][i]]);
	}
	if(low[u] == num[u]){
		res++;
		while(1){
			int v = s.back(); s.pop_back(); visitado[v] = 0;
			//cout << v << " ";
			if(u == v)break;
		}
		//cout << endl;
	}
}

int p,t;

int main(){
	while(cin >> p >> t,(p||t)){
		grafo.assign(p,vi()); low.assign(p,0); num.assign(p,-1);
		visitado.assign(p,-1);
		cin.clear();cin.ignore();
		for(int i = 0; i < p; i++){
			string tmp; getline(cin,tmp);
			//cout << tmp << endl;
			mapper[tmp] = i;
		}
		for(int i = 0; i < t; i++){
			string u,v;
			getline(cin,u); getline(cin,v);
			grafo[mapper[u]].push_back(mapper[v]);
			//cout << u << " " << mapper[u] << "\t" << v << " " << mapper[v] << "\n";
		}
		res = 0,counter=0;
		for(int i = 0; i < p; i++) if(num[i] == -1) dfs(i);
		cout << res << endl;
		mapper.clear();
	}
}
