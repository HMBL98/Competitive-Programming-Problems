#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int m,n,r;
	vector<vii> lista;
	while(cin >> m >> n){
		int * mapa = new int[n+1];
		for(int i = 0,k = -1; i < m; i++){
			cin >> r;
			if(r != 0){
				lista.push_back(vii());
				k++;
			}
			for(int j = 0; j < r; j++){
				int indice;
				cin >> indice;
				mapa[indice]++;
				lista[k].push_back({indice,0});
			}
			for(int j = 0; j < r; j++){
				int valor;
				cin >> valor;
				lista[k][j].second = valor;
			}
		}
		cout << n << " " << m << endl;
		for(int k = 1; k <= n; k++){
			cout << mapa[k] << " ";
			int pos = 1;
			for(int i = 0; i < lista.size(); i++){
				for(int j = 0; j < lista[i].size(); j++){
					if(lista[i][j].first == k){
						cout << pos << " ";
						break;
					}
					pos++;
				}
			}
			cout << endl;
			for(int i = 0; i < lista.size(); i++){
                                for(int j = 0; j < lista[i].size(); j++){
                                        if(lista[i][j].first == k){
                                                cout << lista[i][j].second << " ";
                                        }
                                }
                        }
			cout << endl;

		}
	}
}
