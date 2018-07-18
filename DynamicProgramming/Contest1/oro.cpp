#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n,b,oro,dp[MAX];

int main(){
	cin >> n >> b;
	for(int j = 0; j < n; j++){
		cin >> oro;
		for(int i = MAX-oro-1; i >= 0; i--){
			if(dp[i]){
                    		if(dp[i+oro] == 0 || dp[i+oro] > dp[i] + 1){
					dp[i+oro] = dp[i] + 1;
                 	   	}
			}
                }
            	dp[oro] = 1;
        }
        for(int i = b; i < MAX; i++){
            if(dp[i]){
		cout << i-b << endl;
                break;
            }
        }
    	return 0;
}
