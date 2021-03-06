#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int n,m;

bool posible(int i,int j){
	if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '*' || grid[i][j] == '1') return false;
	return true;
}
void dfs(int i,int j){
	grid[i][j] = '1';
	if(posible(i-1,j-1)) dfs(i-1,j);
	if(posible(i-1,j)) dfs(i-1,j);
	if(posible(i-1,j+1)) dfs(i-1,j+1);
	if(posible(i,j-1)) dfs(i,j-1);
	if(posible(i,j+1)) dfs(i,j+1);
	if(posible(i+1,j-1)) dfs(i+1,j-1);
	if(posible(i+1,j)) dfs(i+1,j);
	if(posible(i+1,j+1)) dfs(i+1,j+1);
}
int main(){
	int caso = 0;
	while(cin >> n >> m, (n||m)){
		for(int i = 0; i < n; i++){
			string tmp; cin >> tmp;
			grid.push_back(tmp);
		}
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == '@') res++, dfs(i,j);
			}
		}
		cout << res << '\n';
		grid.clear();
	}
}
