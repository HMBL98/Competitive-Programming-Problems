//274 - Cat and Mouse
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo1;
vector<vi> grafo2;
vi visitado1,visitado2,visitado3;
int t,r,c,m;
string linea;


void dfs(int u,int opc){
	if(opc == 0){
		visitado1[u] = 1;
		for(int i = 0; i < grafo1[u].size(); i++)if(visitado1[grafo1[u][i]] == -1)dfs(grafo1[u][i],opc);
	}else if(opc == 1){
		visitado2[u] = 1;
                for(int i = 0; i < grafo2[u].size(); i++)if(visitado2[grafo2[u][i]] == -1)dfs(grafo2[u][i],opc);
	}else{
		visitado3[u] = 1;
                for(int i = 0; i < grafo2[u].size(); i++)if(visitado1[grafo2[u][i]] == -1 && visitado3[grafo2[u][i]] == -1)dfs(grafo2[u][i],opc);
	}
}
int caso;
int main(){
	cin >> t;
	while(t--){
		if(caso++)cout<<"\n";
		cin >> r >> c >> m;
		grafo1.assign(r+1,vi());grafo2.assign(r+1,vi());
		visitado1.assign(r+1,-1);visitado2.assign(r+1,-1);
		bool turno = true;
		cin.clear();cin.ignore();
		
		while(getline(cin,linea)){
			if(linea.empty())break;
			stringstream ss(linea);
			int x,y; ss >> x >> y;
			if(x < 0) turno = false;
			else{
				if(turno){
					grafo1[x].push_back(y);
				}else{
					grafo2[x].push_back(y);
				}
			}
		}
		dfs(c,0); dfs(m,1);
		/*for(int i = 1; i <= r; i++) cout << visitado1[i] << " ";
		cout << "\n";
		for(int i = 1; i <= r; i++) cout << visitado2[i] << " ";
                cout << "\n";
		return 1;*/
		int cuantos1 = 0,cuantos2 = 0;
		vector<int> posibles;
		for(int i = 1; i <= r; i++){
			if(visitado1[i] == 1 && visitado2[i] == 1) cuantos1++;
			if(visitado2[i] == 1 && visitado1[i] == -1){
				posibles.push_back(i);
			}
		}
		for(int i = 0; i < posibles.size(); i++){
			if(posibles[i] != m){
				visitado3.assign(r+1,-1);
				dfs(posibles[i],2);
				if(visitado3[m] == 1){
					//cout << posibles[i] << " :D \n";
					cuantos2 = 1;break;
				}
			}
		}
		if(cuantos1) cout << "Y ";
		else cout << "N ";
		if(cuantos2) cout << "Y\n";
		else cout << "N\n";
	}

}
