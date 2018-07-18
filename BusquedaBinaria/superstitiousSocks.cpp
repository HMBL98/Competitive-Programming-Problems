#include <iostream>
using namespace std;

typedef long long ll;
ll socks[100000+500];
ll largos[100000+500];

ll menor(ll n){
	ll m = 1000000;
	for(int i = 0; i < n; i++){
		if(i+largos[i] < n){
			if(socks[i+largos[i]]-socks[i] < m){
				m  = socks[i+largos[i]] - socks[i];
			}
		}
	}
	return m;

}

int main(){
	ll n,k;
	while(cin >> n >> k && (n||k)){
		ll x,y;
		for(int i = 0; i < n; i++){
			largos[i] = 1;
			cin >> socks[i];
		}
		ll minimo = menor(n);	
		ll dia = 0,i = 0;
		while(dia!=k){
			/*cout << "************************" << endl;
			cout << socks[i+largos[i]] << "-" << socks[i] << "----" << minimo << endl;
			cout << "i = " <<  i << endl;
			cout << "largo= " <<  largos[i] << endl;*/
			if(i+largos[i] < n){
				if(socks[i+largos[i]]-socks[i] > minimo){
					i = (i+1 > n-2) ? 0: i+1;
				}else{
					dia++;
					//cout << "Yes " << dia << endl;
					x = socks[i];
					y = socks[i+largos[i]];
					largos[i]++;
					i = ( i == n-2) ? 0: i;
					//largos[i] = (largos[i]+1 <= socks.size()-1) ? largos[i]+1 : largos[i];
					minimo = menor(n);
					//cout << minimo << endl;
					//largos[i]++;
				}
				//cout << "************************" << endl;
			}else{
				i = (i+1 > n-2) ? 0: i+1;
			}
		}
		cout << x << " " << y << endl;
	}
}

