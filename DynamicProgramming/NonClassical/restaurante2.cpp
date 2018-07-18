#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
int n,m,b,tmp,dp[MAX];
int platillo[1000+10];

int main(){
	cin >> n >> m;
	int maximo = 0;
	for(int i = 0; i < n; i++) cin >> platillo[i],maximo += platillo[i];
	for(int i = 0; i < m; i++) cin >> tmp,b += tmp;
	for(int j = 0; j < n; j++){
		for(int i = maximo-platillo[j]-1; i >= 0; i--){
			if(dp[i]){
				dp[i+platillo[j]] = max(dp[i+platillo[j]],dp[i]+1);
			}
                }
            	dp[platillo[j]] = max(dp[platillo[j]],1);
        }
        for(int i = b; i >= 0; i--){
            if(dp[i]){
		cout << dp[i] << " " << i << endl;
                break;
            }
        }
    	return 0;
}
