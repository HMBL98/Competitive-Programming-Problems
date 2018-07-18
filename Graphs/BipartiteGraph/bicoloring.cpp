#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
int n,l;

int main(){
	while(cin >> n,n){
		grafo.assign(n+1,vi());
		cin >> l;
		for(int i = 0; i < l; i++){
			int x,y;
			cin >> x >> y;
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		queue<int> q;
		q.push(0);
		vector<int> visitado(n+1,-1);
		visitado[0] = 1;
		bool status = true;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < (int)grafo[u].size(); i++){
				if(visitado[grafo[u][i]] == visitado[u]) status = false;
				if(visitado[grafo[u][i]] == -1){
					visitado[grafo[u][i]] = !visitado[u];
					q.push(grafo[u][i]);
				}
			}
		}
		if(!status){
			cout << "NOT BICOLORABLE." << endl;
		}else{
			cout << "BICOLORABLE." << endl;
		}
	}
}
