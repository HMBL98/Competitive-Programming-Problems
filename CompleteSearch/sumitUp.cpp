#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
set<string> usadas;
vector<int> numeros;
int t,n;
bool final;
void backtrack(int suma,string s,int j){
	if(suma == t){
		if(usadas.find(s) == usadas.end()){
			final = true;
			cout << s << endl;
			usadas.insert(s);
		}
	}else{
		int tmp;
		string tmp2;
		for(int i = j; i < n; i++){
			tmp = suma; tmp2 = s;
			if(numeros[i]+suma <= t){
				if(!suma){
					tmp2 += std::to_string(numeros[i]);
					backtrack(numeros[i],tmp2,i+1);
				}else{
					tmp2 += '+'; tmp2 += std::to_string(numeros[i]);
					backtrack(numeros[i]+tmp,tmp2,i+1);
				}
			}
		}
	}
}
int main(){
	optimizar_io;
	while(cin >> t >> n && n){
		final = false;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			numeros.push_back(tmp);
		}
		cout << "Sums of " << t << ":" << endl;
		backtrack(0,"",0);
		if(!final){
			cout << "NONE" << endl;
		}
		usadas.clear();
		numeros.clear();
	}

}
