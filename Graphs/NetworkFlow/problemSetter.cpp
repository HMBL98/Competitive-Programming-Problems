//10092 - The Problem with the Problem Setter
#include <bits/stdc++.h>
using namespace std;

#define MAX 1500+10

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int res[MAX][MAX],p[MAX],source,sink,f,mf,nk,np;
typedef vector<int> vi;
vector<vi> graph;

void augment(int v,int minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
int main(){
	optimizar_io;
	while(cin >> nk >> np,(nk||np)){
		int _size = nk+np+2,maxi = 0;
		source = 0, sink = _size-1;
		graph.assign(_size,vi());
		for(int i = 0; i < _size; i++)for(int j = 0; j < _size; j++) res[i][j] = 0;
		for(int i = 0; i < nk; i++){
			int tmp; cin >> tmp;
			//cout << i+np+1 << "-->" << sink << "\n";
			graph[i+np+1].push_back(sink);
			graph[sink].push_back(i+np+1);
			res[i+np+1][sink] = tmp;
			res[sink][i+np+1] = 0;
			maxi += tmp;
		}
		for(int i = 1; i <= np; i++){
			int tmp,category; cin >> tmp;
			for(int j = 0; j < tmp; j++){
				cin >> category;
				//cout << i << "-->" << category+np << "\n";
				graph[i].push_back(category+np);
				graph[category+np].push_back(i);
				res[i][category+np] = 1<<20;
				res[category+np][i] = 0;
			}
			graph[0].push_back(i);
			graph[i].push_back(0);
			res[0][i] = 1;
			res[i][0] = 0;
		}
		mf = 0;
		while(1){
			f = 0;
			for(int i = 0; i < MAX; i++) p[i] = -1;
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
		if(mf == maxi){
			cout << 1 << "\n";
			for(int i = 0; i < nk; i++){
				vi ans;
				for(int j = 1; j <= np; j++)if(res[i+np+1][j]) ans.push_back(j);
				for(int j = 0; j < ans.size(); j++){
					if(j) cout << " ";
					cout << ans[j];
				}
				cout << "\n";
			}
		}else cout << 0 << "\n";
	}
}
