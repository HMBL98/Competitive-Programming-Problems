#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10000+10

int memo[MAX];
int t,n;

/*int dp(int total){
	if(memo[total] != -1) return memo[total];
	if(total == 0) return 0;
	int res = 1<<30;
	for(int i = 1; i*i <= total; i++){
		res = min(res,1+dp(total-i*i));
	}
	memo[total] = res;
	return res;
}*/

int main(){
	memset(memo,-1,sizeof memo);
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> n;
		/*int res = dp(n);
		cout << res << "\n";*/
		for(int i = 0; i <= )
	}
}
