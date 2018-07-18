#include <bits/stdc++.h>
using namespace std;

#define MAX 10000+10
int N,numeros[MAX];

int main(){
	while(scanf("%d",&N), N){
		for(int i = 0; i < N; i++) scanf("%d",&numeros[i]);
		int suma = 0, res = 0;
		for(int i = 0; i < N; i++){
			suma += numeros[i];
			res = max(res,suma);
			if(suma < 0) suma = 0;
		}
		if(res > 0)
			printf("The maximum winning streak is %d.\n",res);
		else
			printf("Losing streak.\n");
	}
}





