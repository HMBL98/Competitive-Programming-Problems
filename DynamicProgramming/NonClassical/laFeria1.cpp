#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::max;
using std::ios_base;

#define MAX 1000000+2
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct info{
	int ini,fin,valor;
};
bool functionSort(info a,info b){
	return a.fin < b.fin;
}

info juegos[MAX+10];
int n,dp[MAX];

int main(){
	optimizar_io;
	cin >> n;

	for(int i = 0; i < n; i++) cin >> juegos[i].ini >> juegos[i].fin >> juegos[i].valor;
	sort(juegos,juegos+n,functionSort);
	//for(int i = 0; i < n; i++)cout << juegos[i].ini << " " << juegos[i].fin <<  " " << juegos[i].valor << endl;
	dp[0] = juegos[0].valor;
	for(int i = 1; i <= n; i++){
		int j = i-1;
		for(; j >= 0; j--) if(juegos[j].fin <= juegos[i].ini) break;
		dp[i] = max(dp[i-1],juegos[i].valor+dp[j]);
	}
	cout << dp[n] << endl;
}
