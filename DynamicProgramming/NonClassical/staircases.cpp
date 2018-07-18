#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
int n,memo[500+10][500+10];

ulli dp(int pos,int total,int nivel){
	if(total == 0 && nivel >= 2) return 1;
	if(memo[pos][total] != -1)return memo[pos][total];
	ulli res = 0;
	for(int i = pos; i <= total; i++){
		res += dp(i,total-i,nivel+1);
	}
	memo[pos][total] = res;
	return res;
}


int main(){
	memset(memo,-1,sizeof memo);
	cin >> n;
	cout << dp(1,n,0) << endl;

}
