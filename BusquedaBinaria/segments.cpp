#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

ll n,k,x,res;
ll arreglo[100000+100];

ll cantidad(ll a,ll b){
	if(a > b) return -1;
	return (b/x)-(a-1)/x;
}
ll lower(ll i,ll ini,ll fin){
	ll mitad;
	while(ini < fin){
		mitad = (ini+fin)/2;
                ll o = cantidad(arreglo[i],arreglo[mitad]);
               	if(k <= o){
			fin = mitad;
		}else{
			ini = mitad+1;
		}
        }
	return ini;
}
ll upper(ll i, ll ini,ll fin){
        ll mitad;
        while(ini < fin){
                mitad = (ini+fin)/2;
               ll o = cantidad(arreglo[i],arreglo[mitad]);
                if(k >= o){
                        ini = mitad+1;
                }else{
                        fin = mitad;
                }
       }
        return ini;
}
int main(){
	optimizar_io;
	cin >> n >> x >> k;
	for(int i = 0; i < n; i++) cin >> arreglo[i];
	sort(arreglo,arreglo+n);
	res = 0;
	for(int i = 0; i < n; i++){
	 ll l = lower(i,0,n);
		ll u = upper(i,0,n);
		//cout << i << " " << l << " " << u << endl;
		res += u-l;
	}
	cout << res << endl;
}
