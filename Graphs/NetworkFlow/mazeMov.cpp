#include <bits/stdc++.h>
using namespace std;

// O(VE^2) Edmonds Karp’s algorithm
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000+10

typedef long long ll;
ll res[MAX][MAX],p[MAX],source,sink,f,mf;
typedef vector<int> vi;
vector<vi> graph;

void augment(int v,ll minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
ll gcd(ll a,ll b){
	return !b ? a : gcd(b,a%b);
}
ll N,values[MAX];

int main(){
	optimizar_io;
	cin >> N;
	graph.assign(N,vi());
	ll mini = 1<<30, maxi = -1;
	for(int i = 0; i < N; i++){
		cin >> values[i];
		if(values[i] < mini){
			mini = values[i];
			source = i;
		}
		if(values[i] > maxi){
			maxi = values[i];
			sink = i;
		}
	}
	for(int i = 0; i < N; i++)for(int j = i+1; j < N; j++){
		ll g = gcd(values[i],values[j]);
		if(g > 1){
			graph[i].push_back(j);
			graph[j].push_back(i);
			res[i][j] = g;
			res[j][i] = g;
		}
	}
	mf = 0;
	while(1){
		f = 0;
		for(int i = 0; i < N; i++) p[i] = -1;
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
		augment(sink,1<<30);
		if(f == 0)break;
		mf += f;
	}
	if(mf >= 1000000000)cout << 1000000000 << "\n";
	else cout << mf << "\n";
}
