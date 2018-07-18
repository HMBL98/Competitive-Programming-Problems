#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> ii;
vector<ii> piezas;
int n,m;
int izq1,izq2,der1,der2;
bool status;
void backtrack(int p,int mask,int anterior){
	if(p == n){
		if(der1 == anterior){
	 		status = true;
		}
		return;
	}
	int maskt;int pt;
	for(int i = 0; i < m; i++){
		maskt = mask;
		if(!(maskt&(1<<i))){
			if(anterior == piezas[i].first){
				maskt |= 1<<i;
				int tmp = p+1;
				backtrack(tmp,maskt,piezas[i].second);
			}
			if(anterior == piezas[i].second){
				maskt |= 1<<i;
				int tmp = p+1;
				backtrack(tmp,maskt,piezas[i].first);
			}
		}
	}
}
int main(){
	optimizar_io;
	while(cin >> n && n){
		cin >> m;
		cin >> izq1 >> izq2;
		cin >> der1 >> der2;
		for(int i = 0; i < m; i++){
			int tmp1,tmp2;
			cin >> tmp1 >> tmp2;
			piezas.push_back({tmp1,tmp2});
		}
		status = false;
		backtrack(0,0,izq2);
		if(status){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		piezas.clear();
	}
}
