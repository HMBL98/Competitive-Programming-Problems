#include <bits/stdc++.h>
using namespace std;
int t,n;
vector<int> rungs;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

bool funtion(int p){
	int a = 0;
	for(int i = 0; i < n; i++){
		if(rungs[i]-a > p){
			return false;
		}else if(rungs[i]-a == p){
			p--;
			a = rungs[i];
		}else{
			a = rungs[i];
		}
	}
	return true;
}
int main(){
	optimizar_io;
	int caso = 0;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			rungs.push_back(tmp);
		}
		sort(rungs.begin(),rungs.end());
		long long  ini = 0, fin = 1e7;
		while(ini < fin){
			long long mitad = (ini+fin)/2;
			if(funtion(mitad)){
				fin = mitad;
			}else{
				ini = mitad+1;
			}
		}
		cout << "Case " << ++caso << ": " << ini << endl;


		rungs.clear();
	}
}
