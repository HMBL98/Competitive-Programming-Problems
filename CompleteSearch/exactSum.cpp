#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	while(cin >> n){
		vector<int> numeros;
		int tmp;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			numeros.push_back(tmp);
		}
		cin >> m;
		sort(numeros.begin(),numeros.end());
		int ini = 0, fin = numeros.size()-1;
		int p1 = 1,p2 = 10000000;
		while(ini < fin){
			int suma = numeros[ini]+numeros[fin];
			if(suma == m){
				int dif = abs(numeros[fin]-numeros[ini]);
				if(dif < abs(p2-p1)){
					p1 = numeros[ini];
					p2 = numeros[fin];
				}
				ini++;
			}else if(suma < m){
				ini++;
			}else{
				fin--;
			}
		}
		cout << "Peter should buy books whose prices are " << p1 << " and " << p2 << "." << endl << endl;
	}
}
