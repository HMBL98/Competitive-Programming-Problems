//10912 - Simple Minded Hashing
#include <bits/stdc++.h>
using namespace std;

int memo[27][27][352];
int l,s;

int dp(int size,int pos,int total){
	if(memo[size][pos][total] != -1) return memo[size][pos][total];
	if(size == l) return (total == s) ? 1 : 0;
	if(size > l) return 0;
	int res = 0;
	for(int i = pos+1; i <= 26; i++)
		if(total+i <= s) res += dp(size+1,i,total+i);
	memo[size][pos][total] = res;
	return res;
}
int main(){
	int caso = 0;
	while(cin >> l >> s,(l||s)){
		for(int i = 0; i < 27; i++)
			for(int j = 0; j < 27; j++)
				for(int k = 0; k < 352; k++) memo[i][j][k] = -1;
		int res = dp(0,0,0);
		cout << "Case " << ++caso << ": " << res << "\n";
	}
}
