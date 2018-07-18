#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int m,n;
vector<string> grid;

int movX[] = {-1,0,0,1};
int movY[] = {0,-1,1,0};

char land;

int getX(int x){
	if(x < 0) x = n-1;
	if(x >= n) x = 0;
	return x;
}
int getY(int y){
	if(y < 0 || y >= m) return -1; 
	return y;
}
int dfs(int x,int y,int color){
	grid[y][x] = (char)('A'+color);
	int res = 1;
	for(int i = 0; i < 4; i++){
		int _x = getX(x+movX[i]), _y = getY(y+movY[i]);
		if(_y != -1 && grid[_y][_x] == land) res += dfs(_x,_y,color);
	}
	return res;
}

int main(){
	while(cin >> m >> n){
		string tmp; int x,y,color = 0;
		grid.clear();
		for(int i = 0; i < m; i++) cin >> tmp,grid.push_back(tmp);
		cin >> y >> x;
		land = grid[y][x];
		dfs(x,y,color);
		int res = 0;
		for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(grid[i][j] == land) res = max(res,dfs(j,i,++color));
		/*for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++) cout << grid[i][j];
			cout << endl;
		}*/
		cout << res << '\n';
	}
}
