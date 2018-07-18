#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arreglo;
	int n;
	cin >> n;
	arreglo.assign(n,0);
	for(int i = 0; i < arreglo.size(); i++){
		cin >> arreglo[i];
	}
	int q;
	while(cin >> q){
		int ini = 0, fin = arreglo.size()-1;
		int mitad;
		while(ini <= fin){
			mitad = (ini+fin)/2;
			if(arreglo[mitad] == q){
				cout << "Found at " << mitad << endl; 
				break;
			}
			if(arreglo[mitad] < q){
				ini = mitad+1;
			}else{
				fin = mitad-1;
			}
		}
	}
}
