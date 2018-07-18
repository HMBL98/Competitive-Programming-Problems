#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<double,double> dd;
map<dd,bool> barras;
int grid[500+10][500+10];
int n;

bool mover(int i,int j){
	if(i < 0 || j < 0 || i >= (n<<1) || j >= (n<<1)+1 || grid[i][j] != 0) return false;
	return true;
}

void dfs(int i,int j,int color){
	grid[i][j] = color;
	//Arriba
	if(mover(i-1,j) && !barras[{j,i-0.5}]) dfs(i-1,j,color);
	//Abajo
	if(mover(i+1,j) && !barras[{j,i+0.5}]) dfs(i+1,j,color);
	//Izquierda
	if(mover(i,j-1) && !barras[{j-0.5,i}]) dfs(i,j-1,color);
	//Derecha
	if(mover(i,j+1) && !barras[{j+0.5,i}]) dfs(i,j+1,color);
}

int main(){
	optimizar_io;
	cin >> n;
	int punto;

	int x,y;
	for(int i = 0; i < (n<<1)-1; i++){
		if(i%2 == 0) x = 0;
		else x = 1;
		for(int j = 0; j < n; j++){
			cin >> punto;
			if(punto){
				//cout << 2*j+x << " " << i+0.5 << endl;
				//cout << 2*j+1+x << "  " << i+0.5 << endl;
				barras[{2*j+x,i+0.5}] = true;
				barras[{2*j+1+x,i+0.5}] = true;
			}else{
				//cout << 2*j+0.5+x << " " << i << endl;
				//cout << 2*j+0.5+x << " " << i+1 << endl;
				barras[{2*j+0.5+x,i}] = true;
				barras[{2*j+0.5+x,i+1}] = true;
			}
		}
	}
	int color = 0;
	int res = 0;
	for(int i = 0; i < (n<<1); i++) for(int j = 0; j < (n<<1)+1; j++) if(!grid[i][j]) res++,dfs(i,j,++color);
	for(int i = 0; i < (n<<1); i++){
		for(int j = 0; j < (n<<1)+1; j++){
			cout << grid[i][j];
		}
		cout << '\n';
	}
	cout << res << endl;
}
