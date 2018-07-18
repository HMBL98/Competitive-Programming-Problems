#include <iostream>
#include <algorithm>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int k;
int arreglo[15];
int main(){
	optimizar_io;
	int caso = 0;
	while(cin >> k && k){
		for(int i = 0; i < k; i++) cin >> arreglo[i];
		sort(arreglo,arreglo+k);
		if(caso > 0) cout << endl;
		for(int i = 0; i < k-5; i++){
			for(int j = i+1; j < k-4; j++){
				for(int l = j+1; l < k-3; l++){
					for(int m = l+1; m < k-2; m++){
						for(int n = m+1; n < k-1; n++){
							for(int o = n+1; o < k; o++){
			cout << arreglo[i] << " " << arreglo[j] << " " << arreglo[l] << " " << arreglo[m] << " " << arreglo[n]
			     << " " << arreglo[o] << endl;
							}
						}
					}
				}
			}
		}
		caso++;
	}
}
