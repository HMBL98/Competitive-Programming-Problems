//spoj // two pointers solutions ver
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

ll n,m;
vector<ll> precios;
int main(){
	optimizar_io;
	cin >> n >> m;
	precios.push_back(0);
	for(int i = 1; i <= n; i++){
		ll tmp;	cin >> tmp;
		precios.push_back(tmp+precios[i-1]);
	}
	/*for(int i = 0; i < precios.size(); i++){
		cout << precios[i] << " ";
	}
	cout << endl;*/
	ll mayor = -1;
	for(int i = 1; i <= n; i++){
		ll ini = i, fin = n+1;
		while(ini < fin){
			ll mitad = (ini+fin)/2;
			//cout << i << " " << mitad << " " << precios[mitad] << "-" << precios[i-1] << endl;
			if(precios[mitad]-precios[i-1] <= m){
				mayor = (precios[mitad]-precios[i-1] > mayor) ? precios[mitad]-precios[i-1] : mayor;
				ini = mitad+1;
			}else{
				fin = mitad;
			}
		}
	}
	cout << mayor << endl;
}
