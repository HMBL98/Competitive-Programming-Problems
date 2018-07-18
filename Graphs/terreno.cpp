#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int punto[1000+10][500+10];
int grid[1000+10][1000+10];
int n;

bool mover(int i,int j){
	if(i < 0 || j < 0 || i >= (n<<1) || j >= (n<<1)+1 || grid[i][j] != 0) return false;
	return true;
}

void dfs(int i,int j,int color){
	grid[i][j] = color;
	//Derecha
	if(mover(i,j+1)){
		if(i == 0){
			if(j%2 != 0 || (j%2 == 0 && punto[i][j/2] == 1))dfs(i,j+1,color);
		}else if(i == (n<<1)-1){
			if(j%2 != 0 || (j%2 == 0 && punto[i-1][j/2] == 1))dfs(i,j+1,color);
		}else{
			if(i%2 == 0){
				int y = (j%2 == 0) ? i : i-1;
				int x = j/2;
				if(punto[y][x] == 1)dfs(i,j+1,color);
			}else{
				int y = (j%2 == 0) ? i-1 : i;
				int x = j/2;
				if(punto[y][x] == 1)dfs(i,j+1,color);
			}
		}
	}
	//Izquierda
	if(mover(i,j-1)){
		if(i == 0){
			if(j%2 == 0 || (j%2 != 0 && punto[i][(j-1)/2] == 1))dfs(i,j-1,color);
		}else if(i == (n<<1)-1){
			if(j%2 == 0 || (j%2 != 0 && punto[i-1][(j-1)/2] == 1))dfs(i,j-1,color);
		}else{
			if(i%2 == 0){
				int y = ((j-1)%2 == 0) ? i : i-1;
				int x = (j-1)/2;
				if(punto[y][x] == 1)dfs(i,j-1,color);
			}else{
				int y = ((j-1)%2 == 0) ? i-1 : i;
				int x = (j-1)/2;
				if(punto[y][x] == 1)dfs(i,j-1,color);
			}
		}
	}
	//Abajo
	if(mover(i+1,j)){
		if(j == 0){
			if(i%2 != 0 || (i%2 == 0 && punto[i][j] == 0))dfs(i+1,j,color);
		}else if(j == (n<<1)){
			if(i%2 == 0 || (i%2 != 0 && punto[i][j/2 -1] == 0))dfs(i+1,j,color);
		}else{
			if(j%2 == 0){
				int y = i;
				int x = (i%2 == 0) ? j/2 : j/2 - 1;
				if(punto[y][x] == 0)dfs(i+1,j,color);
			}else{
				int y = i;
				int x = j/2;
				if(punto[y][x] == 0)dfs(i+1,j,color);
			}
		}
	}
	//Arriba
	if(mover(i-1,j)){
		if(j == 0){
			if(i%2 == 0 || (i%2 != 0 && punto[i-1][j] == 0))dfs(i-1,j,color);
		}else if(j == (n<<1)){
			if(i%2 != 0 || (i%2 == 0 && punto[i-1][j/2 -1] == 0))dfs(i-1,j,color);
		}else{
			if(j%2 == 0){
				int y = i-1;
				int x = ((i-1)%2 == 0) ? j/2 : j/2 - 1;
				if(punto[y][x] == 0)dfs(i-1,j,color);
			}else{
				int y = i-1;
				int x = j/2;
				if(punto[y][x] == 0)dfs(i-1,j,color);
			}
		}
	}
}

int main(){
	optimizar_io;
	cin >> n;
	for(int i = 0; i < (n<<1)-1; i++)for(int j = 0; j < n; j++)cin >> punto[i][j];
	int color = 0,res = 0;
	for(int i = 0; i < (n<<1); i++) for(int j = 0; j < (n<<1)+1; j++) if(!grid[i][j])res++,dfs(i,j,++color);
	/*for(int i = 0; i < (n<<1); i++){
		for(int j = 0; j < (n<<1)+1; j++){
			cout << grid[i][j];
		}
		cout << '\n';
	}*/
	cout << res << '\n';
}
