#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int movX[] = {-1,0,1};
int movY[] = {0,-1,0};

int movX2[] = {-2,-2,0,2,2};
int movY2[] = { 0,-2,-2,-2,0};

int grid[1000][1000];
int l,c,x,y;

bool posible(int i,int j){
	if(i < 0 || j < 0 || i >= l || j >= c || grid[i][j] != -2) return false;
	return true;
}
bool posible2(int i,int j){
        if(i < 0 || j < 0 || i >= l || j >= c || grid[i][j] != -1) return false;
        return true;
}
int caso;
int main(){
	while(cin >> l >> c){
		if(caso++)cout << "\n";
		for(int i = 0; i < l; i++)for(int j = 0; j < c; j++)grid[i][j] = -2;
		for(int i = 0; i < 4*c; i++){
			cin >> y >> x;
			x--,y--;
			grid[abs(l-1-y)][x] = -1;
		}
		cin >> y >> x;
		x--,y--;y = abs(l-1-y);
		queue<ii> q; q.push({y,x});
		grid[y][x] = 0;
		vector<ii> respuestas;

		for(int i = 0; i < 3; i++){
               		if(posible(y+movY[i],x+movX[i])){
                        	grid[y+movY[i]][x+movX[i]] = grid[y][x]+1;
                               	respuestas.push_back({y+movY[i],x+movX[i]});
                      	}
                }
		while(!q.empty()){
			ii u = q.front(); q.pop();
			for(int i = 0; i < 5; i++){
				//cout << u.first << " " << u.second << " " << u.first+movY2[i] << " " << u.second+movX2[i] <<  " " << u.first+(movY2[i]/2) << " " << u.second+(movX2[i]/2) << "\n"; 
				if(posible(u.first+movY2[i],u.second+movX2[i]) && posible2(u.first+(movY2[i]/2),u.second+(movX2[i]/2))){
                                        grid[u.first+movY2[i]][u.second+movX2[i]] = grid[u.first][u.second]+1;
                                        respuestas.push_back({u.first+movY2[i],u.second+movX2[i]});
					q.push({u.first+movY2[i],u.second+movX2[i]});
                                }
			}
		}
		sort(respuestas.begin(),respuestas.end());
		for(int i = 0; i < respuestas.size(); i++)cout << abs(respuestas[i].first-l-1)-1 << " " << respuestas[i].second+1 << " " << grid[respuestas[i].first][respuestas[i].second] << "\n";
		respuestas.clear();
	}
}
