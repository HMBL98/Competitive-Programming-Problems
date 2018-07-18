//10611 - The Playboy Chimp
#include <bits/stdc++.h>
using namespace std;

#define MAX 50000+10
typedef long long ll;

ll altura[MAX];
ll n,q,mono,ini,fin;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> altura[i];
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> mono;

		ini = 0,fin = n;
                while(ini < fin){
                        ll mitad = (ini+fin) >> 1;
                        if(mono > altura[mitad]) ini = mitad+1;
                        else fin = mitad;
                }
		if(ini-1 < 0 || ini-1 > n-1) cout << "X ";
		else cout << altura[ini-1] << " ";
	
		ini = 0,fin = n;
		while(ini < fin){
			ll mitad = (ini+fin) >> 1;
			if(mono < altura[mitad]) fin = mitad;
			else ini = mitad+1;
		}
		if(ini < 0 || ini > n-1) cout << "X\n";
		else cout << altura[ini] << "\n";
	}
}
