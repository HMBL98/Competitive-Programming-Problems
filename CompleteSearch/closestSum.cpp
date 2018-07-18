#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
#include <algorithm>
using std::sort;
using std::abs;
using std::min;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
ll N,M,Q; ll array[1000+100];
ll solve(ll suma){
	ll mini = 10000000;
	ll res;
	for(int i = 0; i < N; i++){
        	for(int j = i+1; j < N && array[i] != array[j]; j++){
                	ll tmp = array[i]+array[j];
                        if(tmp == suma) return tmp;
                        if(abs(suma-tmp) < mini){res = tmp; mini = abs(suma-tmp);}
                }
	}
	return res;
}
int main(){
	optimizar_io;
	int caso = 0;
	while(cin >> N && N){
		for(int i = 0; i < N; i++){
			cin >> array[i];
		}
		//sort(array,array+N);
		cin >> Q;
		ll suma;
		cout << "Case " << ++caso << ":" << endl;
		for(int k = 0; k < Q; k++){
			cin >> suma;
			ll res = solve(suma);
			cout << "Closest sum to " << suma << " is " << res << "." << endl;
		}
	}
}
