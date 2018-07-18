#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,m,k;
	cin >> n >> m >> k;

	long long ini = 1, fin = (long long)n*(long long)m;
	while(ini <= fin){
		long long mitad = (ini+fin)/2;
		long long a = 0;
		for(int i = 1; i <= n; i++){
			a += m<(mitad/i)? m : (mitad/i);
		}
		cout << "hay " << a << " menores a " << mitad << endl;
		if(a < k){
			ini = mitad+1;
		}else{
			fin = mitad-1;
		}
	}
	cout << ini << endl;
	return 0;
}

