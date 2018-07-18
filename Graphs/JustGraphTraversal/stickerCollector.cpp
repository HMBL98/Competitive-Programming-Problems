#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int n,m,s,res,x,y;
enum Orientacion {arriba,izquierda,derecha,abajo};
vector<string> grid;

bool mover(int i,int j){
	if(i < 0 || j < 0 || i >= m || j >= n || grid[j][i] == '#') return false;
	else{
		//cout << i << " " << j << " " << grid[j][i] << endl;
		if(grid[j][i] == '*'){
			grid[j][i] = '.';
			res++;
		}
		return true;
	}
}
int main(){
	optimizar_io;
	while(cin >> n >> m >> s,(n||m||s)){
		grid.clear();
		res = 0;
		string s;
		for(int i = 0; i < n; i++) cin >> s,grid.push_back(s);
		Orientacion ori;
		for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
			switch(grid[i][j]){
				case 'N':
					x = j; y = i;
					ori = arriba;
				break;
				case 'S':
					x = j; y = i;
					ori = abajo;
				break;
				case 'L':
					x = j; y = i;
					ori = derecha;
				break;
				case 'O':
					x = j; y = i;
					ori = izquierda;
				break;
			}
		}
		//cout << x << " " << y << endl;
		string movs;
		cin >> movs;
		for(int i = 0; i < movs.size(); i++){
			switch(movs[i]){
				case 'D':
					if(ori == arriba){
						ori = derecha;
					}else if(ori == abajo){
						ori = izquierda;
					}else if(ori == izquierda){
						ori = arriba;
					}else{
						ori = abajo;
					}
				break;
				case 'E':
					if(ori == arriba){
						ori = izquierda;
					}else if(ori == abajo){
						ori = derecha;
					}else if(ori == izquierda){
						ori = abajo;
					}else{
						ori = arriba;
					}
				break;
				case 'F':
					if(ori == arriba){
						if(mover(x,y-1)) y--;
					}else if(ori == abajo){
						if(mover(x,y+1)) y++;
					}else if(ori == izquierda){
						if(mover(x-1,y)) x--;
					}else{
						if(mover(x+1,y)) x++;
					}
				break;
			}
		}
		cout << res << '\n';
	}
}
