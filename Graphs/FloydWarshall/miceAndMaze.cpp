//1112 - Mice and Maze
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int matriz[101][101];
int t,n,m,e,ti,x,y,w,caso;

int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		if(caso++)cout << "\n";
		cin >> n >> e >> ti>> m;
		for(int i = 0; i <= n; i++)for(int j = 0; j <= n; j++)if(i == j) matriz[i][j] = 0; else matriz[i][j] = 1<<20;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> w;
			matriz[x][y] =  w;
		}
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					matriz[i][j] = min(matriz[i][j],matriz[i][k]+matriz[k][j]);

		int res = 0;
		for(int i = 1; i <= n; i++) if(matriz[i][e] <= ti) res++;
		cout << res << "\n";

	}

}

