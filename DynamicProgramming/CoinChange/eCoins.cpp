#include <bits/stdc++.h>
using namespace std;
#define MAX 40+10
int n,m,s;
double valores[MAX],monedas[MAX];

int main(){
	cin >> n;
	while(n--){
		memset(monedas,1e6,sizeof monedas);
		cin >> m >> s;
		for(int i = 0; i < m; i++){
			double x,y;
			cin >> x >> y;
			valores[i] = sqrt(x*x+y*y);
			cout << valores[i] << endl;
		}
		monedas[0] = 1;
		for(int i = 1; i <= s; i++){
			for(int j = 0; j < m; j++){
				if(valores[j] <= i && monedas[i-(int)valores[j]] < monedas[i]){
					monedas[i] = monedas[i-(int)valores[j]];
				}
			}
			monedas[i]++;
			//printf("%d %d\n",i,monedas[i]);
		}
		printf("%d\n",monedas[s]);
		/*if(!mon)
			printf("not possible\n",res);
		else
			printf("%d\n",res);*/
	}
}
