//10354 - Avoiding Your Boss
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
set<int> usado;
int padre[101][101];
int grafo[101][101];
vector< pair<int,ii> > pares;
int p,r,bh,of,h,m,x,y,c;


void path(int i,int j){
	if(i != j)path(i,padre[i][j]);
	//cout << j << " ";
	usado.insert(j);
}

int main(){
	while(cin >> p >> r >> bh >> of >> h >> m){
		for(int i = 1; i <= p; i++)for(int j = 1; j <= p; j++){
                        padre[i][j] = i;
			if(i == j) grafo[i][j] = 0;
                        else grafo[i][j] = 1<<20;
                }
		for(int i = 0; i < r; i++){
			cin >> x >> y >> c;
			grafo[x][y] = c;
			grafo[y][x] = c;
			pares.push_back({x,{y,c}});
		}
		for(int k = 1; k <= p; k++){
			for(int i = 1; i <= p; i++){
				for(int j = 1; j <= p; j++){
					if(grafo[i][k]+grafo[k][j] < grafo[i][j]){
						grafo[i][j] = grafo[i][k]+grafo[k][j];
						padre[i][j] = padre[k][j];
					}
				}
			}
		}
		path(bh,of);
		//cout << "\n";
		for(int i = 1; i <= p; i++)for(int j = 1; j <= p; j++){
			if(i == j) grafo[i][j] = 0;
			else grafo[i][j] = 1<<20;
		}
		for(int i = 0; i < pares.size(); i++){
                        grafo[pares[i].first][pares[i].second.first] = pares[i].second.second;
                        grafo[pares[i].second.first][pares[i].first] = pares[i].second.second;
                }
		for(int k = 1; k <= p; k++){
                        for(int i = 1; i <= p; i++){
                                for(int j = 1; j <= p; j++){
                                        if(usado.find(i) == usado.end() && usado.find(j) == usado.end() && usado.find(k) == usado.end() && grafo[i][k]+grafo[k][j] < grafo[i][j]){
                                                grafo[i][j] = grafo[i][k]+grafo[k][j];
                                        }
                                }
                        }
                }
		if(grafo[h][m] != 1<<20) cout << grafo[h][m] << "\n";
		else cout << "MISSION IMPOSSIBLE.\n";
		pares.clear();
		usado.clear();
	}

}


