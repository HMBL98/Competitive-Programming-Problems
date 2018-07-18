//10474 - Where is the Marble?
#include <iostream>
#include <algorithm>
using namespace std;


int arreglo[10005];
//1 2 3 5
int busqueda(int n, int x){
	int ini = 0;
	int fin = n-1;
	while(ini <= fin){
		int mitad = (ini+fin)/2;
		if(arreglo[mitad] == x){
			for(int i = ini; i < mitad; i++){
				if(arreglo[i] == x){
					return i;
				}
			}
			return mitad;
		}else{
			if(arreglo[mitad] < x){
				ini = mitad+1;
			}else{
				fin = mitad-1;
			}
		}
	}
	return -1;
}

int main(){
	int n,q;
	int nquery = 0;
	while(1){
		cin >> n >> q;
		if(n == 0 && q == 0) break;
		nquery++;
		for(int i = 0; i < n; i++){
			cin >> arreglo[i];
		}
		sort(arreglo,arreglo+n);
		cout << "CASE# " << nquery << ":\n";
		for(int i = 0; i < q; i++){
			int query;
			cin >> query;
			int pos = busqueda(n,query);
			if(pos == -1){
				cout << query << " not found\n";
			}else{
				cout << query << " found at " << pos + 1 << '\n';
			}
		}
	}

}
