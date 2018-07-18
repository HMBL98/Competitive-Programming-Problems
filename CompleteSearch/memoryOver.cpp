#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int t,c,k,res;
string cadena;
map<char,int> info;

int main(){
	optimizar_io;
	int caso = 0;
	cin >> t;
	while(t--){
		cin >> c >> k;
		cin >> cadena;
		res = 0;
		for(int i = 0; i < c; i++){
			if(info.find(cadena[i]) == info.end() || info[cadena[i]] == 0){
				info[cadena[i]] = k+1;
			}else{
				if(info[cadena[i]] > 0){
					info[cadena[i]] = k+1;
					res++;
				}
			}
			for(map<char,int>::iterator it= info.begin(); it != info.end(); it++){
				it->second = (it->second > 0) ? it->second-1 : 0;
			}
		}
		cout << "Case " << ++caso << ": " << res << endl;
		info.clear();
	}
}
