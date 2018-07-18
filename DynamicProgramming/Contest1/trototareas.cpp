#include <bits/stdc++.h>
using namespace std;
int n,s;
pair<int,int> info[500+10];
int memo[500+10][100+10];

int dp(int pos,int total){
	if(total <= 0) return 0;
	if(pos == n) return 1<<30;
	if(memo[pos][total] != -1)return  memo[pos][total];
	int tomar  = dp(pos+1,total-info[pos].first)+info[pos].second;
	int notomar = dp(pos+1,total);
	memo[pos][total] = min(tomar,notomar);
	return min(tomar,notomar);
}
int main(){
	memset(memo,-1,sizeof memo);
	cin >> n >> s;
	for(int i = 0; i < n; i++)cin >> info[i].first >> info[i].second;
	int res = dp(0,s);
	cout << res << endl;
}
