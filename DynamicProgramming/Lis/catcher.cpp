#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	int caso = 0;
	while(scanf("%d",&t), t != -1){
		if(caso>=1) printf("\n");		
		vector<int> numeros; int tmp;
		numeros.push_back(t);
		while(scanf("%d",&tmp), tmp != -1){
			numeros.push_back(tmp);
		}
		int lis[numeros.size()];
		memset(lis,0,sizeof lis);
		lis[0] = 1;
		int mayor = 1;
		for(int i = 1; i < numeros.size(); i++){
			for(int j = 0; j < i; j++){
				if(numeros[j] >= numeros[i]){
					lis[i] = max(lis[j],lis[i]);
				}
			}
			lis[i]++;
			mayor = max(mayor,lis[i]);
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",++caso,mayor);
	}
}
