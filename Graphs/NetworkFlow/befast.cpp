#include <bits/stdc++.h>
using namespace std;


#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10000+10000+10
typedef vector<int> vi;
vector<vi> graph;


int res[MAX][MAX],p[MAX],source,sink,mf,f;

void augment(int v,int minEdge){
	if(v == source){f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}


int N,M;

int main(){
	optimizar_io;
	while(cin >> N >> M,(N||M)){
		int _size = N+N+1;
		for(int i = 0; i <= _size+10; i++)for(int j = 0; j <= _size+10; j++) res[i][j] = 0;
		source = 0; sink = _size;
		graph.assign(_size+1,vi());
		for(int i = 0; i < M; i++){
			int x,y; cin >> x >> y;
			graph[x+1].push_back(y+N+1);
			graph[y+N+1].push_back(x+1);
			res[x+1][y+N+1] = 1<<20;
			res[y+N+1][x+1] = 0;
		}
		for(int i = 1; i <= N; i++){
			graph[0].push_back(i);
			graph[i].push_back(0);
			res[0][i] = 1;
			res[i][0] = 0;

			graph[i+N].push_back(sink);
			graph[sink].push_back(i+N);
			res[i+N][sink] = 1;
			res[sink][i+N] = 0;
		}
		mf = 0;
		while(1){
			f = 0;
			for(int i = 0; i <= _size+10; i++)p[i] = -1;
			queue<int> q; q.push(source);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == sink)break; 
				for(int i = 0; i < graph[u].size(); i++){
					int v = graph[u][i];
					if(res[u][v] > 0 && p[v] == -1){
						p[v] = u; q.push(v);
					}
				}
			}
			augment(sink,1<<20);
			if(f == 0) break;
			mf += f;
		}
		cout << mf << "\n";
	}
}
