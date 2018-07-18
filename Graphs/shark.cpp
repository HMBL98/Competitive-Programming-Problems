#include <bits/stdc++.h>
using namespace std;

int cubetas[8];
int movX[] = {-1,0,0,1};
int movY[] = {0,-1,1,0};
char grid[70][70];
int t,l,c;

bool posible(int i,int j){
	if(i < 0 || i >= l || j < 0 || j >= c || grid[i][j] == 'V') return false;
	return true;
}
int pos1X,pos1Y;
int pos2X,pos2Y;

int dfs(int i,int j,char m){
	grid[i][j] = 'V';
	int res = 1;
	if(j > pos2X){
		pos2Y = i;
		pos2X = j;
	}else if(j == pos2X){
		pos2Y = max(i,pos2Y);
	}
	for(int k = 0; k < 4; k++){
		if(posible(i+movY[k],j+movX[k]) && grid[i+movY[k]][j+movX[k]] == m) res += dfs(i+movY[k],j+movX[k],m);
	}
	return res;
}
int caso;
int main(){
	cin >> t;
	while(t--){
		if(caso++)cout<< "\n";
		for(int i = 0; i < 8; i++)cubetas[i] = 0;
		cin >> l >> c;
		for(int i = 0; i < l; i++)for(int j = 0; j < c; j++) cin >> grid[i][j];
		for(int i = 0; i < l; i++){
			for(int j = 0; j < c; j++){
				if(grid[i][j] >= 'a' && grid[i][j] <= 'z' && grid[i][j] != 'V'){
					pos2X = 0; pos2Y = 0;
					int area = dfs(i,j,grid[i][j]);
					//cout << j << " "<< i << "\t" << pos2X << " " << pos2Y << "\t" << area << "\n";
					if(area != (pos2X-j+1)*(pos2Y-i+1)){
						cubetas[7]++;
					}else{
						if(area == 1){
							cubetas[0]++;
						}else if(area == 2){
							cubetas[1]++;
						}else{
							if((abs(pos2X-j+1) == 1 || abs(pos2Y-i+1) == 1)) cubetas[2]++;
							if((abs(pos2X-j+1) == 2 && abs(pos2Y-i+1) > 2)||(abs(pos2X-j+1) > 2 && abs(pos2Y-i+1) == 2))cubetas[3]++;
							if(abs(pos2X-j+1) == abs(pos2Y-i+1)) cubetas[4]++;
							if((abs(pos2X-j+1) == 3 && abs(pos2Y-i+1) > 3)||(abs(pos2X-j+1) > 3 && abs(pos2Y-i+1) == 3))cubetas[5]++;
							if((abs(pos2X-j+1) == 4 && abs(pos2Y-i+1) > 4)||(abs(pos2X-j+1) > 4 && abs(pos2Y-i+1) == 4) ) cubetas[6]++;
						}
					}
				}
			}
		}
		for(int i = 0; i < 8; i++){
			if(i)cout << " ";
			cout << cubetas[i];
		}
		cout << "\n";
	}
}
