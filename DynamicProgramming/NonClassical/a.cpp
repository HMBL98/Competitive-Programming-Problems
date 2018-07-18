#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 400+10 
int n,k,m;
struct persona{
	int x,y,b;
};
persona personas[MAX];
int cantidad[MAX];
int memo[MAX][MAX];
int dp(int dia,int alumno,int comida){
	if(memo[dia][alumno] != -1) return memo[dia][alumno];
	if(dia > n || alumno > m)return 0;
	int tomar1 = -1e6,tomar2 = -1e6,notomar1 = -1e6,notomar2 = -1e6;
	int res = -1e6;
	if(personas[alumno].x <= dia && personas[alumno].y >= dia && personas[alumno].b <= comida){
		tomar1 = 1+dp(dia,alumno+1,comida-personas[alumno].b);
		tomar2 = 1+dp(dia+1,1,comida-personas[alumno].b+cantidad[dia+1]);
	}
	notomar1 = dp(dia,alumno+1,comida);
	notomar2 = dp(dia+1,alumno,comida+cantidad[dia+1]);
	res = max(res,tomar1); res = max(res,tomar2); res = max(res,notomar1); res = max(res,notomar2);
	memo[dia][alumno] = res;
	return res;
}

int main(){
	optimizar_io;
	memset(memo,-1,sizeof memo);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> cantidad[i], cantidad[i] -= k;
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> personas[i].x >> personas[i].y >> personas[i].b;
	int res = dp(1,1,cantidad[1]);
	cout << res << endl;
}
