#include <bits/stdc++.h>
using namespace std;

#define MAX 1000+10

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int res[MAX][MAX],p[MAX],source,sink,f;
typedef vector<int> vi;
vector<vi> graph;
int n,r,k,weigth[MAX][MAX],caso;

void augment(int v,int minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
int flow(int mid){
	int mf = 0;
	for(int i = 0; i <= 2*n+1; i++)for(int j = i+1; j <= 2*n+1; j++){
		res[i][j] = 1;
		res[j+1][i] = 0;
	}
	while(1){
		f = 0;
		for(int i = 0; i < MAX; i++) p[i] = -1;
		queue<int> q; q.push(source);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == sink) break;
			for(int i = 0; i < graph[u].size(); i++){
				int v = graph[u][i];
				if(weigth[u][v] <= mid && res[u][v] > 0 && p[v] == -1){
					p[v] = u; q.push(v);
				}
			}
		}
		augment(sink,1<<20);
		if(f == 0)break;
		mf += f;
	}
	return mf;
}
int main(){
	optimizar_io;
	while(cin >> n,n){
		cin >> r;
		graph.assign(MAX,vi());
		for(int i = 1; i <= n; i++){
			graph[2*i].push_back(2*i-1);
			graph[2*i-1].push_back(2*i);
		}
		for(int i = 0; i < r; i++){
			int x,y,c; cin >> x >> y >> c;
			if(y < x)swap(x,y);
			graph[2*x].push_back(2*y-1);
			graph[2*y-1].push_back(2*x);
			weigth[2*x][2*y-1] = c;
                        weigth[2*y-1][2*x] = c;
		}
		cin >> k;
		source = 0; sink = 2*n+1;
		int ini = 0, fin = 1<<20;
		while(ini < fin){
			int mid = (ini+fin)>>1;
			if(flow(mid) >= k) fin = mid;
			else ini = mid+1;
		}
		cout << "Case " << ++caso << ": ";
		if(flow(ini) == k) cout << ini << "\n";
		else cout << "no solution\n";
	}
}
