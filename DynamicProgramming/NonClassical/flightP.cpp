#include <bits/stdc++.h>
using namespace std;
#define MAX 100000+10
int N,x;
int info[10][MAX];
int memo[1000+10][10];
int dp(int pos,int altitud){
	if(altitud < 0 || altitud > 9) return 1e6;
	if(pos == (x/100))return 0;
	if(pos == (x/100)-1 && altitud > 1)return 1e6;
	if(memo[pos][altitud] != -1) return memo[pos][altitud];
	int uno,dos,tres;
	int res = 1e6;
	uno = dos = tres = 1e6;
	if(altitud > 0 && altitud < 9){
		uno = -1*info[altitud-1][pos]+20+dp(pos+1,altitud-1);
		dos = -1*info[altitud][pos]+30+dp(pos+1,altitud);
		tres = -1*info[altitud+1][pos]+60+dp(pos+1,altitud+1);
	}else if(altitud > 0){
		uno = -1*info[altitud-1][pos]+20+dp(pos+1,altitud-1);
		dos = -1*info[altitud][pos]+30+dp(pos+1,altitud);
	}else{
                dos = -1*info[altitud][pos]+30+dp(pos+1,altitud);
               	tres = -1*info[altitud+1][pos]+60+dp(pos+1,altitud+1);
	}
	res = min(res,min(uno,min(dos,tres)));
	memo[pos][altitud] = res;
	return memo[pos][altitud];
}
int main(){
	scanf("%d",&N);
	while(N--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&x);
		for(int i = 9; i >= 0; i--)
			for(int j = x/100-1; j >= 0; j--)
				scanf("%d",&info[i][j]);
		int res = dp(0,0);
		printf("%d\n\n",res);
	}
}
