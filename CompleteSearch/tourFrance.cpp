#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <cstdio>
using std::printf;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int f,r;
int frente[20], atras[20];
vector<double>datos;
int main(){
	optimizar_io;
	while(cin >> f && f){
		cin >> r;
		for(int i = 0; i < f; i++) cin >> frente[i];
		for(int i = 0; i < r; i++) cin >> atras[i];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < f; j++){
				double d = (double)atras[i]/(double)frente[j];
				datos.push_back(d);
			}
		}
		sort(datos.begin(),datos.end());
		double mayor = -1.0;
		for(int i = 1; i < datos.size(); i++){
			mayor = (datos[i]/datos[i-1] > mayor) ? datos[i]/datos[i-1] : mayor;			
		}
		printf("%.2f\n",mayor);

		datos.clear();
	}
}
