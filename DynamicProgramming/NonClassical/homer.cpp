#include <bits/stdc++.h>
using namespace std;
#define MAX 10000+10
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int n,m,t;
int cantidad[MAX],diferencia[MAX],valores[2];
int main(){
	while(scanf("%d %d %d",&m,&n,&t) != EOF){
		memset(cantidad,0,sizeof cantidad);
		memset(diferencia,1e6,sizeof diferencia);
		valores[0] = m; valores[1] = n;
		diferencia[0] = 0;
		for(int i = 1; i <= t; i++){
			if(valores[0] > i && valores[1] > i){
				diferencia[i] = i;
				cantidad[i] = 0;
			}else{
				for(int j = 0; j < 2; j++){
					if(valores[j] <= i && diferencia[i-valores[j]] <= diferencia[i]){
						if(diferencia[i-valores[j]] == diferencia[i])cantidad[i] = max(cantidad[i],cantidad[i-valores[j]]+1);
						else cantidad[i] = cantidad[i-valores[j]]+1;
						diferencia[i] = diferencia[i-valores[j]];

					}
				}
			}
		}
		if(diferencia[t] != 0)	printf("%d %d\n",cantidad[t],diferencia[t]);
		else printf("%d\n",cantidad[t]);
	}
}
