#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

vector<string> grid;
int t,n;

int moverX[] = {-1,0,0,1};
int moverY[] = {0,-1,1,0};

int getX(int x){
	if(x < 0 || x >= n) return -1;
	return x;
}
int getY(int y){
	if(y < 0 || y >= n) return -1;
	return y;
}
void dfs(int y,int x){
	grid[y][x] = 'V';
	for(int i = 0; i < 4; i++){
		int _x = getX(x+moverX[i]);
		int _y = getY(y+moverY[i]);
		if(_x != -1 && _y != -1 && (grid[_y][_x] == 'x' || grid[_y][_x] == '@')) dfs(_y,_x);
	}
}
int main(){
	optimizar_io;
	cin >> t;
	int caso = 0;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			string tmp; cin >> tmp;
			grid.push_back(tmp);
		}
		int res = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(grid[i][j] == 'x') res++,dfs(i,j);
		cout << "Case " << ++caso << ": " << res << '\n';
		grid.clear();
	}
}
