//SPOJ MBALL - Feline Olympics - Mouseball
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ll;
int t,n,values[5] = {2,3,6,7,8};

ll memo[5][100000+10];

ll dp(int pos,int total){
	if(total == 0)return 1;
	if(pos > 4)return 0;
	if(memo[pos][total] != -1)return memo[pos][total];

	ll tomar = 0,notomar = 0;
	notomar += dp(pos+1,total);

	if(total-values[pos] >= 0)tomar += dp(pos,total-values[pos]);
	memo[pos][total] = tomar+notomar;
	return tomar+notomar;
}
int main(){
	optimizar_io;
	for(int i = 0; i < 5; i++)for(int j = 0; j < 100000+10; j++)memo[i][j] = -1;
	cin >> t;
	while(t--){
		cin >> n;
		cout << dp(0,n) << "\n";
	}
}
