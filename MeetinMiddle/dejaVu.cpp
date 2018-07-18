#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long int ll;
ll n,k,p,values[40],res;
vector<ll> X,Y;

void computeSubArray(bool left,int t,int idx){
	for(int i = 1; i < (1<<t); i++){
		ll prod = 1;
		for(int j = 0; j < t; j++){
			if(i&(1<<j)) prod *= values[j+idx];
		}
		if(left) X.push_back(prod);
		else Y.push_back(prod);
		if(prod >= k) res++;
	}
}
int main(){
	optimizar_io;
	cin >> n >> k >> p;
	for(int i = 0; i < n; i++) cin >> values[i];
	computeSubArray(true,n/2,0);
	computeSubArray(false,n-n/2,n/2);

	/*for(int i = 0; i < X.size(); i++) cout << X[i] << " ";
	cout << "\n";
	for(int i = 0; i < Y.size(); i++) cout << Y[i] << " ";
	cout << "\n";*/

	sort(Y.begin(),Y.end());
	for(int x = 0; pow(10,x) <= p; x++){
		for(int i = 0; i < X.size(); i++) if(X[i]*pow(10,x) >= k) res++;
		for(int i = 0; i < Y.size(); i++) if(Y[i]*pow(10,x) >= k) res++;
	}
	for(int i = 0; i < X.size(); i++){
               	ll ini = 0,fin = Y.size();
                while(ini < fin){
                	ll mitad = (ini+fin) >> 1;
                     	if((X[i]+Y[mitad]) >= k) fin = mitad;
                       	else ini = mitad+1;
                }
        	res += Y.size()-ini;
       	}
	for(int x = 0; pow(10,x) <= p; x++){
		for(int i = 0; i < X.size(); i++){
			ll ini = 0,fin = Y.size();
			while(ini < fin){
				ll mitad = (ini+fin) >> 1;
				if((X[i]+Y[mitad])*pow(10,x) >= k) fin = mitad;
				else ini = mitad+1;
			}
			res += Y.size()-ini;
		}
	}
	cout << res << "\n";
}
