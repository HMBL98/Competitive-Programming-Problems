#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int T,n,p;
int numeros[20];
bool status;


void backtrack(int o,int j){
	if(o == 0){
		status = true;
		return;
	}
	if(o < 0 || j == p) return;
	for(int i = j; i < p; i++){
		backtrack(o-numeros[i],i+1);
	}
}

int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		status = false;
		cin >> n;
		cin >> p;
		for(int i = 0; i < p; i++)cin >> numeros[i];
		sort(numeros,numeros+p);
		backtrack(n,0);
		if(status){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
