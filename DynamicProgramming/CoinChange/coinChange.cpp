#include <bits/stdc++.h>
using namespace std;

int n,k,q;
vector<int> monedas;
int main(){
	while(cin >> n >> q){
		for(int i = 0; i < n; i++){
			int tmp; cin >> tmp;
			monedas.push_back(tmp);
		}
		vector<int> minimo(1000+1,1e6);
		minimo[0] = 0;
		for(int i = 1; i <= 1000; i++){
			for(int j = 0; j < n; j++){
				if(monedas[j] <= i && minimo[i-monedas[j]]+1 < minimo[i]){
					minimo[i] = minimo[i-monedas[j]]+1;
				}
			}
		}
		while(q--){
			cin >> k;
			cout << minimo[k] << endl;
		}
	}
}
