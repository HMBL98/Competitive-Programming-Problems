#include <bits/stdc++.h>
using namespace std;

#define MAX 100+1
int t,r,c,m,n,w,grid[MAX][MAX];
int pares,impares;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
bool validar(int x,int y){
	if(x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == -2) return false;
	return true;
}
void dfs(int x,int y){
	if(grid[x][y] == 1) return;
	grid[x][y] = 1;
	int movs = 0;
	set< pair<int,int> > vistos;
	if(vistos.find(make_pair(x+m,y+n)) == vistos.end() && validar(x+m,y+n)){
		vistos.insert(make_pair(x+m,y+n));
		movs++;dfs(x+m,y+n);
	}
	if(vistos.find(make_pair(x+m,y-n)) == vistos.end() && validar(x+m,y-n)){
		vistos.insert(make_pair(x+m,y-n));
		movs++;dfs(x+m,y-n);
	}
	if(vistos.find(make_pair(x-m,y+n)) == vistos.end() && validar(x-m,y+n)){
		vistos.insert(make_pair(x-m,y+n));
		movs++;dfs(x-m,y+n);
	}
	if(vistos.find(make_pair(x-m,y-n)) == vistos.end() && validar(x-m,y-n)){
		vistos.insert(make_pair(x-m,y-n));
		movs++;dfs(x-m,y-n);
	}

	if(vistos.find(make_pair(x+n,y+m)) == vistos.end() && validar(x+n,y+m)){
		vistos.insert(make_pair(x+n,y+m));
		movs++;dfs(x+n,y+m);
	}
	if(vistos.find(make_pair(x+n,y-m)) == vistos.end() && validar(x+n,y-m)){
		vistos.insert(make_pair(x+n,y-m));
		movs++;dfs(x+n,y-m);
	}
	if(vistos.find(make_pair(x-n,y+m)) == vistos.end() && validar(x-n,y+m)){
		vistos.insert(make_pair(x-n,y+m));
		movs++;dfs(x-n,y+m);
	}
	if(vistos.find(make_pair(x-n,y-m)) == vistos.end() && validar(x-n,y-m)){
		vistos.insert(make_pair(x-n,y-m));
		movs++;dfs(x-n,y-m);
	}

	if(movs != 0 && movs%2 == 0) pares++;
	if(movs != 0 && movs%2 != 0) impares++;
}
void clearGrid(){
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) grid[i][j] = -1;
}
int main(){
	optimizar_io;
	cin >> t;
	int caso = 0;
	while(t--){
		clearGrid();
		cin >> r >> c >> m >> n >> w;
		pares = impares = 0;
		for(int i = 0; i < w; i++){
			int x,y;
			cin >> x >> y;
			grid[x][y] = -2;
		}
		dfs(0,0);
		if(!pares && !impares) cout << "Case " << ++caso << ":" << " " << 1 << " " << 0 << endl;
		else cout << "Case " << ++caso << ":" << " " << pares << " " << impares << endl;
	}
}
