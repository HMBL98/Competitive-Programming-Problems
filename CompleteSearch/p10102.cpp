#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> ii;
vector<ii> unos;
vector<ii> tres;
int M;
int main(){
	optimizar_io;
	while(cin >> M){
		string tmp;
		for(int i = 0; i < M; i++){
			cin >> tmp;
			for(int j = 0; j < M; j++){
				if(tmp[j]-'0' == 1){
					unos.push_back({i,j});
				}
				if(tmp[j]-'0' == 3){
					tres.push_back({i,j});
				}
			}
		}
		int mayor = -1;
		int menor;
		for(int i = 0; i < unos.size(); i++){
			menor = 1000000;
			for(int j = 0; j < tres.size(); j++){
				int tmp = abs(unos[i].first-tres[j].first)
                                          + abs(unos[i].second -tres[j].second);
				menor = (tmp < menor) ? tmp : menor;
			}
			mayor = (menor > mayor) ? menor : mayor;
		}
		cout << mayor << endl;
		unos.clear(); tres.clear();
	}
}
