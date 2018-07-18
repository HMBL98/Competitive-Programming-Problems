#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int L;
typedef vector<L> VL;
typedef vector<VL> VVL;

#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second

typedef long long ll;

const int MAXN=1000;
typedef ll tf;
typedef ll tc;
const tf INFFLUJO = 1LL << 60;
const tc INFCOSTO = 1LL << 60;
struct edge {
  int u, v;
  tf cap, flow;
  tc cost;
  tf rem() { return cap - flow; }
};
int nodes; //numero de nodos
vector<int> G[MAXN]; // limpiar!
vector<edge> e;  // limpiar!
void addEdge(int u, int v, tf cap, tc cost) {
  G[u].pb(sz(e)); e.pb((edge){u,v,cap,0,cost});
  G[v].pb(sz(e)); e.pb((edge){v,u,0,0,-cost});
}
tc dist[MAXN], mnCost;
int pre[MAXN];
tf cap[MAXN], mxFlow;
bool in_queue[MAXN];
void flow(int s, int t) {
  zero(in_queue);
  mxFlow=mnCost=0;
  while(1){
    fill(dist, dist+nodes, INFCOSTO); dist[s] = 0;
    memset(pre, -1, sizeof(pre)); pre[s]=0;
    zero(cap); cap[s] = INFFLUJO;   
    queue<int> q; q.push(s); in_queue[s]=1;
    while(sz(q)){
      int u=q.front(); q.pop(); in_queue[u]=0;
      for(auto it:G[u]) {
        edge &E = e[it];
        if(E.rem() && dist[E.v] > dist[u] + E.cost + 1e-9){ // ojo EPS
          dist[E.v]=dist[u]+E.cost;
          pre[E.v] = it;
          cap[E.v] = min(cap[u], E.rem());
          if(!in_queue[E.v]) q.push(E.v), in_queue[E.v]=1;
        }
      }
    }
    if (pre[t] == -1) break;
    mxFlow +=cap[t];
    mnCost +=cap[t]*dist[t];
    for (int v = t; v != s; v = e[pre[v]].u) {
      e[pre[v]].flow += cap[t];
      e[pre[v]^1].flow -= cap[t];
    }
  }
}

//int u[MAXN],v[MAXN];
//ll cst[MAXN],D,K;
VVL p;

L Costo(int a,int b){
  return p[a][0]*p[b][2]*p[b][2]+p[a][1]*p[a][1]*p[b][1]+p[a][2]*p[b][0]*p[b][0];
}

int main() {
  int N, M;
  int In = 0,Out = 0;
  cin >> N;

  p = VVL(N,VL(5));
  for(int i = 0 ; i < N ; i ++){
    for(int j = 0 ; j < 5 ; j ++)
      cin >> p[i][j] ;
    In += p[i][3];
    Out += p[i][4];
  }
  nodes = 2*N+2;

  if(In != Out){
    cout << "Imposible\n";
    return 0;
  }

  for(int i = 0 ; i < N ; i ++)
    addEdge(2*N,i,p[i][3],0);

  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j ++){
      if(i == j) continue;
      addEdge(i,N+j,1,Costo(i,j));
    }
  }

  for(int i = 0 ; i < N ; i ++)
    addEdge(N+i,2*N+1,p[i][4],0);
  
  flow(2*N,2*N+1);   
  
  if(mxFlow != In){
    cout << "Imposible\n";
  } else {
    cout << mnCost <<'\n';
    for(int i = 0 ; i < N ; i ++)              
      for(auto it:G[i]) {
        edge &E = e[it];
        if(E.flow == 1 ){          
          cout << i+1 << ' ' << E.v-N+1 << ' ' << Costo(i,E.v-N) <<  '\n';
        }
      }
  }
  return 0;
}
