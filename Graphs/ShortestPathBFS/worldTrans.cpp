#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
typedef vector<int> vi;
vector<vi> grafo;
vi visitado;

map<string,int> mapper;
vector<string> palabras;
int t,idx,caso; string s,source,destination;

vector<ss> pares;
int main(){
	cin >> t;
	while(t--){
		if(caso++) cout << "\n";
		idx = 0;
		while(cin >> s){
			if(s[0] == '*') break;
			mapper[s] = ++idx;
			palabras.push_back(s);
		}
		cin.clear(); cin.ignore();
		while(getline(cin,s)){
			if(s.empty())break;
			stringstream ss(s);
			ss >> source;
			ss >> destination;
			pares.push_back({source,destination});
		}
		grafo.assign(palabras.size()+1,vi());
		for(int i = 0; i < palabras.size(); i++){
			for(int j = i+1; j < palabras.size(); j++){
				if(palabras[i].size() == palabras[j].size()){
					int contador = 0;
					for(int k = 0; k < palabras[i].size(); k++) if(palabras[i][k] != palabras[j][k]) contador++;
					if(contador == 1){
						grafo[mapper[palabras[i]]].push_back(mapper[palabras[j]]);
						grafo[mapper[palabras[j]]].push_back(mapper[palabras[i]]);
					}
				}
			}
		}
		for(int i = 0; i < pares.size(); i++){
			visitado.assign(palabras.size()+1,-1);
			queue<int> q;
			q.push(mapper[pares[i].first]);
			visitado[mapper[pares[i].first]] = 0;
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int i = 0; i < grafo[u].size(); i++){
					if(visitado[grafo[u][i]] == -1){
						visitado[grafo[u][i]] = visitado[u]+1;
						q.push(grafo[u][i]);
					}
				}
			}
			cout << pares[i].first << " " << pares[i].second << " " << visitado[mapper[pares[i].second]] << "\n";
		}
		pares.clear();
		palabras.clear();
		mapper.clear();
	}
}
