#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define MAX 1000+10
typedef pair<int,int> ii;
int n,m,pesoTotal,valores[MAX];
ii memo[MAX][MAX];

ii dp(int pos,int total){
	if(memo[pos][total].first != -1) return memo[pos][total];
	ii res(0,total);
	for(int i = pos; i < n; i++){
		ii tmp(0,total);
		if(total+valores[i] <= pesoTotal){
			tmp = dp(i+1,total+valores[i]);
			tmp.first++;
		}
		if(tmp.second > res.second){
			res = tmp;
		}
		if(tmp.second == res.second){
			res.first = max(res.first,tmp.first);
		}
	}
	memo[pos][total] = res;
	return res;
}
int main(){
	optimizar_io;
	for(int i = 0; i < MAX; i++)for(int j = 0; j < MAX; j++) memo[i][j].first = -1,memo[i][j].second = -1;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)scanf("%d",&valores[i]);
	int total = 0, tmp;
	for(int i = 0; i < m; i++) scanf("%d",&tmp), total += tmp;
	pesoTotal = total;
	ii res = dp(0,0);
	printf("%d %d\n",res.first,res.second);
}
