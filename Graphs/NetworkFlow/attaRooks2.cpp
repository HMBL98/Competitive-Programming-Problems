#include <bits/stdc++.h>
using namespace std;

// O(VE^2) Edmonds Karp’s algorithm
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 100+10
#define MAXV 1000+10
int res[MAXV][MAXV],p[MAXV],source,sink,f,mf;
typedef vector<int> vi;
vector<vi> graph;

void augment(int v,int minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
int N;char grid[MAXN][MAXN];

int main(){
	optimizar_io;
	while(cin >> N){
		source = 0, sink = 2*N+1;
		graph.assign(sink+1,vi());
		for(int i = 0; i < sink+1; i++)for(int j = 0; j < sink+1; j++) res[i][j] = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> grid[i][j];
			}
		}
		/*for(int i = 1; i <= N; i++)for(int j = 1; j <= N; j++){
			if(grid[i-1][j-1] == '.'){
				//cout << i << " " << j << "\n";
	                        graph[i].push_back(j+N);
        	                graph[j+N].push_back(i);
                	        res[i][j+N] = 1<<20;
                        	res[j+N][i] = 0;
			}
                }*/
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(grid[i][j] == '.'){
					int k = j;
					while(grid[i][k] == '.' && k < N){
						cout << i+1 << " " << k+1 << "\n";
						graph[i+1].push_back(k+N+1);
						graph[k+N+1].push_back(i+1);
						res[i+1][k+N+1] = 1<<20;
						res[k+N+1][i+1] = 0;
						k++;
					}
				}
			}
		}
		for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                                if(grid[j][i] == '.'){
                                        int k = j;
                                        while(grid[k][i] == '.' && k < N){
                                                graph[i+1].push_back(k+N+1);
                                                graph[j+N+1].push_back(i+1);
                                                res[i+1][k+N+1] = 0;
                                                res[k+N+1][i+1] = 1<<20;
                                                k++;
                                        }
                                }
                        }
                }

		for(int i = 0; i < N; i++){
			int _s = 0;
			bool point = false;
			for(int j = 0; j < N; j++){
				if(grid[i][j] == '.') point = true;
				if(j-1 >= 0 && j+1 <= N-1 && grid[i][j] == 'X' && grid[i][j-1] == '.' && grid[i][j+1] == '.'){
					_s++;
				}
			}
			if(point) _s++;
			else _s = 0;
			//cout << source << " " << i+1 << " --- " <<  _s << "\n";
			graph[source].push_back(i+1);
			graph[i+1].push_back(source);
			res[source][i+1] = _s;
			res[i+1][source] = 0;
		}
		for(int i = 0; i < N; i++){
                        int _s = 0;
			bool point = false;
                        for(int j = 0; j < N; j++){
				if(grid[j][i] == '.') point = true;
                                if(j-1 >= 0 && j+1 <= N-1 && grid[j][i] == 'X' && grid[j-1][i] == '.' && grid[j+1][i] == '.'){
                                        _s++;
                                }
                        }
			if(point) _s++;
			else _s = 0;
			//cout << i+1+N << " "  << sink << " ---" << _s << "\n";
			graph[i+1+N].push_back(sink);
                        graph[sink].push_back(i+1+N);
                        res[i+1+N][sink] = _s;
                        res[sink][i+1+N] = 0;
                }
		mf = 0;
		while(1){
			f = 0;
			for(int i = 0; i <= sink+1; i++) p[i] = -1;
			queue<int> q; q.push(source);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == sink) break;
				for(int i = 0; i < graph[u].size(); i++){
					int v = graph[u][i];
					if(res[u][v] > 0 && p[v] == -1){
						p[v] = u; q.push(v);
					}
				}
			}
			augment(sink,1<<20);
			if(f == 0)break;
			mf += f;
		}
		/*for(int i = 0; i < graph.size(); i++){
			for(int j = 0; j < graph.size(); j++) cout << res[i][j] << " ";
			cout << "\n";
		}*/
		cout << mf << "\n";
	}
}
