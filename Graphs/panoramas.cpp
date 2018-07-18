#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi objetivos,visitado,padre;
int v,s;


int main(){
	cin >> v >> s;
	int tmp;
	grafo.assign(v+1,vi());
	visitado.assign(v+1,-1);
	padre.assign(v+1,-1);
	for(int i = 0; i < s; i++) cin >> tmp, objetivos.push_back(tmp);
	for(int i = 0; i < v; i++){
		int x,y; cin >> x >> y;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
	for(int i = 0; i <= objetivos.size(); i++){
		if(visitado[objetivos[i]] == -1){
			queue<int> q; q.push(objetivos[i]);
			padre[objetivos[i]] = 0;
			visitado[objetivos[i]] = 0;
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int j = 0; j < grafo[u].size(); j++){
					if(visitado[grafo[u][j]] == -1){
						q.push(grafo[u][j]);
						padre[grafo[u][j]] = u;
						visitado[grafo[u][j]] = visitado[u]+1;
					}
				}
			}
		}
	}
	/*for(int i = 1; i <= v; i++){
		cout << i << " " << visitado[i] << " " << padre[i] << endl;
	}*/
	set<int> res;
	int actual;
	for(int i = 0; i < objetivos.size(); i++){
		actual = objetivos[i];
		do{
			res.insert(actual);
			actual = padre[actual];
		}while(actual != 0);
	}
	cout << res.size() << endl;

}
