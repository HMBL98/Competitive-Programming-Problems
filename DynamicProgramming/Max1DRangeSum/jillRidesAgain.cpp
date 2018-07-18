#include <bits/stdc++.h>
using namespace std;
int t,r;

int main(){
	cin >> t;
	while(t--){
		vector<int> paradas;
		cin >> r;
		r--;
		while(r--){
			int tmp; cin >> tmp;
			paradas.push_back(tmp);
		}
		int suma = 0;
		int res = 0;
		for(int i = 0; i < paradas.size(); i++){
			suma  += paradas[i];
			if(suma > res){
				res = suma;
			}
			if(suma < 0){
				suma = 0;
			}
		}
		cout << res << endl;
	}
}
