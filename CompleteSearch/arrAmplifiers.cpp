#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int t,n;
int arreglo[100000+100];
bool mayor(int a,int b){
	double ab = b;
	double ba = a*(log(b)/log(a));
	return ab < ba;
}
int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> n;
		int unos = 0;
		int indice = 0;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			if(tmp != 1){
				arreglo[indice] = tmp;
				indice++;
			}else{
				unos++;
			}
		}
		sort(arreglo,arreglo+indice);
		if(unos){
			for(int i = 0; i < unos; i++)cout << "1 ";
			for(int i = 0; i < indice; i++)cout << arreglo[i] << " ";
			cout << endl;
		}else{
			for(int i = indice-1; i > 1; i--){
                        	cout << arreglo[i] << " ";
 	 	       	}
			if(indice > 1){
				if(mayor(arreglo[0],arreglo[1])){
                        	       cout << arreglo[0] << " " << arreglo[1] << endl;
	                        }else{
        	                       cout << arreglo[1] << " " << arreglo[0] << endl;
                	        }
			}else{
				cout << arreglo[0] << endl;
			}
		}
	}
}
