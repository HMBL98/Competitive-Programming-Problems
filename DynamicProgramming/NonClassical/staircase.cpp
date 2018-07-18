#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll memo[550][550];

ll dp(int pos,int total){
	if(memo[pos][total] != -1)return memo[pos][total];
	if(total == n) return 1;
	if(total > n)return 0;
	if(pos >= n)return 0;
	ll tomar = dp(pos+1,total+pos);
	ll notomar = dp(pos+1,total);
	memo[pos][total] = tomar+notomar;
	return tomar+notomar;
}
int main(){
	for(int i = 0; i < 501; i++)for(int j = 0; j < 501; j++)memo[i][j] = -1;
	cin >> n;
	cout << dp(1,0) << "\n";
}
