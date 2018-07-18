//929 - Number Maze
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int t,n,m,valores[1000][1000],dist[1000][1000];
int movX[] = {-1,0,0,1};
int movY[] = {0,-1,1,0};

bool posible(int i,int j){
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return true;
}

int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i <= n; i++)for(int j = 0; j <= m; j++) dist[i][j] = 1<<20;
		for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> valores[i][j];
		// dist,nodo
		priority_queue<iii, vector<iii>, greater<iii>> p; p.push(iii(valores[0][0],{0,0}));
		dist[0][0] = valores[0][0];
		while(!p.empty()){
			iii act = p.top(); p.pop();
			int d = act.first; ii u = act.second;
			if(d > dist[u.first][u.second]) continue;
			for(int i = 0; i < 4; i++){
				if(posible(u.first+movY[i],u.second+movX[i]) && dist[u.first][u.second]+valores[u.first+movY[i]][u.second+movX[i]] < dist[u.first+movY[i]][u.second+movX[i]]){
					dist[u.first+movY[i]][u.second+movX[i]] = dist[u.first][u.second]+valores[u.first+movY[i]][u.second+movX[i]];
					p.push(iii(dist[u.first+movY[i]][u.second+movX[i]],{u.first+movY[i],u.second+movX[i]}));
				}
			}
		}
		//for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << i << " " << j << " " << dist[i][j] << "\n";
		cout << dist[n-1][m-1] << "\n";
	}
}
