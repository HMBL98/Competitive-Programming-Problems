#include <bits/stdc++.h>
using namespace std;

int movX[] = {-1,0,0,1};
int movY[] = {0,-1,1,0};
vector<string> grid;
string linea;
int caso;

bool posible(int i,int j,char c){
	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != ' ') return false;
	return true;
}

void dfs(int i,int j,char c){
	grid[i][j] = c;
	for(int k = 0; k < 4; k++) if(posible(i+movY[k],j+movX[k],c)) dfs(i+movY[k],j+movX[k],c);
}

int main(){
	while(getline(cin,linea)){
		if(linea[0] == '_'){
			bool status = false;
			char borde;
			for(int i = 0; i < grid.size(); i++){
				for(int j = 0; j < grid[i].size(); j++){
					if(!status && grid[i][j] != ' ' && grid[i][j] != '-'){
						status = true;
						borde = grid[i][j];
						continue;
					}
					if(grid[i][j] != ' ' && grid[i][j] != borde) dfs(i,j,grid[i][j]);
				}
			}
			for(int i = 0; i < grid.size(); i++) cout << grid[i] << "\n";
			cout << linea << "\n";
			grid.clear();
		}else{
			grid.push_back(linea);
		}
	}
}
