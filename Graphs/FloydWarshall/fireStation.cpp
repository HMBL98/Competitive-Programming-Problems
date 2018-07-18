#include <bits/stdc++.h>
using namespace std;

#define MAX 500
int grafo[MAX][MAX];
int fireS[100];

int t,n,f,x,y,c,caso;
string linea;


int main(){
	cin >> t;
	while(t--){
		if(caso++)cout << "\n";
		cin >> f >> n;
		for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
				if(i == j) grafo[i][j] = 0;
				else grafo[i][j] = 1<<20;
		}
		for(int i = 0; i < f; i++) cin >> fireS[i], fireS[i]--;
		cin.clear(); cin.ignore();
		while(getline(cin,linea)){
			if(linea.empty()) break;
			stringstream ss(linea);
			ss >> x >> y >> c;
			x--; y--;
                        grafo[x][y] = c;
                        grafo[y][x] = c;
		}
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					grafo[i][j] = min(grafo[i][j],grafo[i][k]+grafo[k][j]);
				}
			}
		}
		int minimo = 1<<20;
		int idx;
		for(int i = 0; i < n; i++){ // nueva estacion
			int tmp = -1;
			fireS[f] = i;
			//cout << i+1 << "\n";
			for(int j = 0; j < n; j++){ //actual
				int tmp2 = 1<<20;
				for(int k = 0; k <= f; k++){
					//cout << j+1 << " " << fireS[k]+1 << " " << grafo[j][fireS[k]] << "\n";
					tmp2 = min(tmp2,grafo[j][fireS[k]]);
				}
				tmp = max(tmp,tmp2);
			}
			//cout << "\n";
			if(tmp < minimo){
				minimo = tmp;
				idx = i+1;
			}
		}
		cout << idx << "\n";

	}
}

