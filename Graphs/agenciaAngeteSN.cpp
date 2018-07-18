//D. La Agencia del Agente Solid Nieves
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000000+10

int costo[MAX],n;
string s,d;

int main(){
	optimizar_io;
	cin >> n >> s >> d;
	for(int i = 0; i < n; i++) cin >> costo[i];
	long long res = 0;
	if(s.compare(d) == 0)for(int i = 0; i < n; i++) if(s[i] == '1') res += costo[i];
	while(s.compare(d) != 0){
		int mayor = -1;
		int idx1 = -1;
		for(int i = 0; i < n; i++){
			if(s[i] == '1' && d[i] == '0' && costo[i] > mayor){
				mayor = costo[i];
				idx1 = i;
			}
		}
		if(idx1 != -1) s[idx1] = '0';
		else{
			int menor = INT_MAX;
			int idx = -1;
			for(int i = 0; i < n; i++){
				if(s[i] == '0' && d[i] == '1' && costo[i] < menor){
					menor = costo[i];
					idx = i;
				}
			}
			if(idx != -1) s[idx] = '1';
		}
		for(int i = 0; i < n; i++){
			if(s[i] == '1') res += costo[i];
		}
	}
	cout << res << '\n';
}

