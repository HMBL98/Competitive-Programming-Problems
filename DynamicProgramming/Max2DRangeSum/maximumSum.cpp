#include <bits/stdc++.h>
using namespace std;
#define MAX 100+10
int N;
int matriz[MAX][MAX];
int main(){
	while(scanf("%d",&N) != EOF){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				scanf("%d",&matriz[i][j]);
				if(i > 0) matriz[i][j] += matriz[i-1][j];
				if(j > 0) matriz[i][j] += matriz[i][j-1];
				if(i > 0 && j > 0) matriz[i][j] -= matriz[i-1][j-1];
			}
		}
		int res = -1e6;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int k = i; k < N; k++){
					for(int l = j; l < N; l++){
						int tmp = matriz[k][l];
						if(i > 0) tmp -= matriz[i-1][l];
						if(j > 0) tmp -= matriz[k][j-1];
						if(i > 0 && j > 0) tmp += matriz[i-1][j-1];
						res = max(tmp,res);
					}
				}
			}
		}
		printf("%d\n",res);
	}
}
