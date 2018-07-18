//codeforces
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

ll n,m;
vector<ll> a;
int main(){
	optimizar_io;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		ll tmp; cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end());
	for(int i = 0; i < m; i++){
		ll tmp; cin >> tmp;
		ll ini = 0, fin = n;
		while(ini < fin){
			ll mitad = (ini+fin)/2;
			if(tmp >= a[mitad]){
				ini = mitad+1;
			}else{
				fin = mitad;
			}
		}
		if(i) cout << " ";
		cout << ini;
	}
	cout << endl;
}
