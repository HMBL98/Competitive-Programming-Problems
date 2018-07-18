#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int n;
bool isPrime(int i){
	if(i ==2 || i == 3 || i == 5 || i == 7 || i == 11 ||
   	   i == 13 || i == 17 || i == 19 || i == 23 || i == 29 ||
	   i == 31 || i == 37){
		return true;
	}
	return false;
}
void backtrack(int mask,vector<int> res,int anterior){
	if(mask == (1<<n)-1 && isPrime(anterior+1)){
		for(int i = 0; i < res.size(); i++){
			cout << res[i];
			if(i != res.size()-1) cout << " ";
		}
		cout << endl;
		return;
	}
	int maskt;vector<int> tmp;
	for(int i = 2; i <= n; i++){
		maskt = mask;tmp = res;
		if(!(maskt&(1<<(i-1)))){
			if(isPrime(anterior+i)){
				maskt |= 1<<(i-1);
				tmp.push_back(i);
				backtrack(maskt,tmp,i);
			}
		}
	}
}
int main(){
	optimizar_io;
	int caso = 0;
	while(cin >> n){
		if(caso) cout << endl;
		cout << "Case " << ++caso << ":" << endl;
		if(n == 1){
			cout << "1" << endl;
		}else{
			vector<int> tmp; tmp.push_back(1);
			backtrack(1,tmp,1);
		}
	}
}

