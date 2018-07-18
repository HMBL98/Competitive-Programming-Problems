//Codeforces
#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> numeros;
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		numeros.push_back(tmp);
	}
	if(k == 1){
		cout << 1 << " " << 1 << endl;
	}else{
	int ini = 0, fin = n+1;
	int a = -1,b = -1;
	while(ini < fin){
		int mitad = (ini+fin)/2;
		bool status = false;
		set<int> distintos;
		for(int i = 0; i <= n-mitad; i++){
			for(int j = 0; j < mitad; j++){
				distintos.insert(numeros[i+j]);
			}
			if(distintos.size() == k){
				a = i;
				b = i+mitad-1;
				status = true;
				break;
			}
			distintos.clear();
		}
		cout << ini << " " << fin << " " << mitad << " " << status << endl;
		if(status){
			fin = mitad;
		}else{
			ini = mitad+1;
		}
	}
	if(a != -1){
		cout << a+1 << " " << b+1 << endl;
	}else{
		cout << -1 << " " << -1 << endl;
	}
	}
}
