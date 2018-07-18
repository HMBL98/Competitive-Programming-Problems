//RAIN3 - Rain
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1500000+10

int casos,n,m,s[MAX],t[MAX],a[MAX];

int main(){
	optimizar_io;
	cin >> casos;
	while(casos--){
		cin >> s[0] >> t[0] >> n >> m;
		a[0] = 0;
		for(int i = 1; i <= n; i++){
			s[i] = (78901 + 31*s[i-1])%699037;
			t[i] = (23456 + 64*t[i-1])%2097151;
			a[i] = (s[i]%100+1)*(t[i]%100+1)+a[i-1];
		}
		int ini = 1, fin = 1<<20;
		while(ini < fin){
			int mit = (ini+fin)>>1;
			bool status = true;
			if(mit > n) status = false;
			else{
				for(int i = 1; i <= n; i++){
					if(i+mit-1 > n)break;
					if(a[i+mit-1]-a[i-1] > m){
						status = false;
						break;
					}
				}
			}
			if(status) ini = mit+1;
			else fin = mit;
		}
		cout << ini-1 << "\n";
	}
}

