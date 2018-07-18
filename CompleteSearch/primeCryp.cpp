#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
vector<int> conjunto(10,0);
int mascara;
int res;
int n;
void backtrack(vector<int> elegidos){
	if(elegidos.size() == 5){
		long long uno = elegidos[0]*100+elegidos[1]*10+elegidos[2];
		long long producto1 = uno*elegidos[3];
		string p1 = to_string(producto1);
		if(p1.size() > 3) return;
		for(int j = 0; j < 3; j++){
			if(!(mascara&(1<<(p1[j]-'0')))) return;
		}
		long long producto2 = uno*elegidos[4];
		string p2 = to_string(producto2);
                if(p2.size() > 3) return;
                for(int j = 0; j < 3; j++){
                	if(!(mascara&(1<<(p2[j]-'0')))) return;
               	}
		long long dos = elegidos[3]*10+elegidos[4];
		long long producto3 = uno*dos;
		string p3 = to_string(producto3);
                if(p3.size() > 4) return;
                for(int j = 0; j < 4; j++){
                	if(!(mascara&(1<<(p3[j]-'0')))) return;
                }
		//cout << uno << " " << dos << endl;
		res++;
		return;
	}
	vector<int> tmp;
	for(int i = 0; i < n; i++){
		tmp = elegidos;
		tmp.push_back(conjunto[i]);
		backtrack(tmp);
	}
}
int main(){
	optimizar_io;
	while(cin >> n){
		mascara = 0;
		res = 0;
		for(int i = 0; i < n; i++){
			cin >> conjunto[i];
			mascara |= 1 << conjunto[i];
		}
		vector<int> a;
		backtrack(a);
		cout << res << endl;
		conjunto.clear();
	}
}
