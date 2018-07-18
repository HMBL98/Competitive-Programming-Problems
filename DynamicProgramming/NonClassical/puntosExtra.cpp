#include <bits/stdc++.h>
using namespace std;

#define MAX 400+10 
int n,k,m;
struct persona{
	int x,y,b;
};
persona personas[MAX];
int cantidad[MAX];
/*int memo[1000][1000][1000];
int dp(int dia,int alumno,int comida){
	cout << dia << " " << alumno << " " << comida << endl;
	if(memo[dia][alumno][comida] != -1) return memo[dia][alumno][comida];
	if(dia > n || alumno > m)return 0;
	int tomar1 = -1e6,tomar2 = -1e6,notomar1 = -1e6,notomar2 = -1e6;
	int res = -1e6;
	if(personas[alumno].x <= dia && personas[alumno].y >= dia && comida-personas[alumno].b >= 0){
			tomar1 = 1+dp(dia,alumno+1,comida-personas[alumno].b);
			tomar2 = 1+dp(dia+1,1,comida-personas[alumno].b+cantidad[dia+1]);
	}
	notomar1 = dp(dia,alumno+1,comida);
	notomar2 = dp(dia+1,1,comida+cantidad[dia+1]);
	res = max(res,tomar1); res = max(res,tomar2); res = max(res,notomar1); res = max(res,notomar2);
	memo[dia][alumno][comida] = res;
	return res;
}*/
int memo[400][400];
int dp(int dia,int alumno,int comida){
        if(dia > n || alumno > m)return 0;
        if(memo[dia][alumno] != -1) return memo[dia][alumno];
        int tomar1 = -1e6,tomar2 = -1e6,notomar1 = -1e6,notomar2 = -1e6;
        int res = -1e6;
        if(personas[alumno].x <= dia && personas[alumno].y >= dia && comida-personas[alumno].b >= 0){
                        tomar1 = 1+dp(dia,alumno+1,comida-personas[alumno].b);
                        tomar2 = 1+dp(dia+1,1,comida-personas[alumno].b+cantidad[dia+1]);
        }
        notomar1 = dp(dia,alumno+1,comida);
        notomar2 = dp(dia+1,1,comida+cantidad[dia+1]);
        res = max(res,tomar1); res = max(res,tomar2); res = max(res,notomar1); res = max(res,notomar2);
        memo[dia][alumno] = res;
        return res;
}

int main(){
	memset(memo,-1,sizeof memo);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> cantidad[i], cantidad[i] -= k;
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> personas[i].x >> personas[i].y >> personas[i].b;
	int res = dp(1,1,cantidad[1]);
	cout << res << endl;
}
