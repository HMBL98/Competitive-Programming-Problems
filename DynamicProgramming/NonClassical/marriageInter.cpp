//10446 - The Marriage Interview :-)
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[65][65];

ll trib(int n,int back){
	if(n <= 0) return 1;
	if(n == 1) return 1;
	if(dp[n][back] != -1) return dp[n][back];
	ll sum = 1;
	for(int i = 1; i <= back; i++)sum += trib(n-i,back);
	dp[n][back] = sum;
	return sum;
}
int n,m,caso;
int main(){
	for(int i = 0; i < 65; i++) for(int j = 0; j < 65; j++) dp[i][j] = -1;
	while(cin >> n >> m){
		if(n > 60) break;
		cout << "Case " << ++caso << ": " << trib(n,m) << "\n";
	}
}

