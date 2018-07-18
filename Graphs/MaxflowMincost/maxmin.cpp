#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(c) ((int)c.size())
#define pb push_back
#define MAXN 153
#define INFFLUJO (1LL<<60)
#define INFCOSTO (1LL<<60)

typedef long long ll;

struct edge{
	int u, v;
  	ll cap, flow;
  	ll cost;
  	ll rem() { return cap - flow; }
};

int nodes; //numero de nodos
vector<int> G[MAXN]; // limpiar!
vector<edge> e;  // limpiar!
void addEdge(int u, int v, ll cap, ll cost){
	G[u].pb(sz(e)); e.pb((edge){u,v,cap,0,cost});
  	G[v].pb(sz(e)); e.pb((edge){v,u,0,0,-cost});
}
ll dist[MAXN], mnCost;
int pre[MAXN];
ll cap[MAXN], mxFlow;
bool in_queue[MAXN];
void flow(int s, int t){
	for(int i = 0; i <= nodes; i++) in_queue[i] = 0;
  	mxFlow = mnCost = 0;
  	while(1){
		for(int i = 0; i <= nodes; i++){
			dist[i] = INFCOSTO;
    			pre[i] = -1;
			cap[i] = 0;
		}
		dist[s] = 0; pre[s] = 0; cap[s] = INFFLUJO;
    		queue<int> q; q.push(s); in_queue[s]=1;
    		while(sz(q)){
      			int u=q.front(); q.pop(); in_queue[u]=0;
      			for(auto it:G[u]){
        			edge &E = e[it];
        			if(E.rem() && dist[E.v] > dist[u] + E.cost+1e-9){ // ojo EPS
          				dist[E.v]=dist[u]+E.cost;
          				pre[E.v] = it;
          				cap[E.v] = min(cap[u], E.rem());
          				if(!in_queue[E.v]) q.push(E.v), in_queue[E.v]=1;
        			}
      			}
    		}
    		if(pre[t] == -1) break;
    		mxFlow += cap[t];
    		mnCost += cap[t]*dist[t];
    		for(int v = t; v != s; v = e[pre[v]].u){
      			e[pre[v]].flow += cap[t];
      			e[pre[v]^1].flow -= cap[t];
    		}
  	}
}
int N,inDeg,outDeg,src,snk;
ll in[MAXN][5];
ll Costo(int a,int b){
	return in[a][0]*in[b][2]*in[b][2]+in[a][1]*in[a][1]*in[b][1]+in[a][2]*in[b][0]*in[b][0];
}

int main(){
	optimizar_io;
	cin >> N;
	nodes = 2*N+2;
	src = 0; snk = 2*N+1;
	for(int i = 1; i <= N; i++){
		cin >> in[i][0] >> in[i][1] >> in[i][2] >> in[i][3] >> in[i][4];
		inDeg += in[i][3]; outDeg += in[i][4];
		addEdge(src,2*i,in[i][3],0);
		addEdge(2*i-1,snk,in[i][4],0);

	}

	if(inDeg != outDeg){
		cout << "Imposible\n";
		return 0;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i == j)continue;
			addEdge(2*i,2*j-1,1,Costo(i,j));
		}
	}
	flow(src,snk);

	if(mxFlow != inDeg) cout << "Imposible\n";
	else{
		cout << mnCost << "\n";
		for(int i = 1; i <= N; i++)
      			for(auto it:G[2*i]){
        			edge &E = e[it];
        			if(E.flow == 1 ){
					cout << i << " " << (E.v+1)/2 << " " << E.cost << "\n";
				}
        		}
	}
	return 0;
}
