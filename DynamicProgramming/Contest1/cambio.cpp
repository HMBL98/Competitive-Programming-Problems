#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int v,b,n,m,monedas[MAX],productos[MAX];

int monedas(int pos,int total,int mask){
	if(total == 0)return 1;
	if(pos == n) return 0;
	if(monedas[pos] <= total) return 1;
	int tomar  
}
int dp(int pos,int total){
	if(posible(total) && total != v) return total;
	if(pos == m) return 0;
	int tomar  = 1<<30, notomar = 1<<30;
	if(productos[pos] <= total) tomar  = dp(pos,total-productos[pos]);
	notomar = dp(pos+1,total);
	return min(tomar,notomar);
}
int main(){
	cin >> v >> b >> n >> m;
	for(int i = 0; i < n; i++)cin >> monedas[i];
	for(int i = 0; i < m; i++)cin >> productos[i];

	int res = dp(0,v);
	cout << res << endl;
}
