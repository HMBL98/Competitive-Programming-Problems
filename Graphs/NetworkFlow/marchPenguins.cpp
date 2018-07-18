#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define INF (1LL<<60)
typedef long long Flujo;
typedef long long Costo;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;
typedef vector<int> Lista;
typedef pair<float,float> ff;

struct GrafoFlujo{
	struct AristaFlujo{
        	int dst; AristaFlujo* residual;
        	Flujo cap, flujo;
        	AristaFlujo(int d, Flujo f, Flujo c) : dst(d), flujo(f), cap(c){}
        	void AumentarFlujo(Flujo f){
            		residual->flujo -= f;
            		this->flujo += f;
        	}
    	};
    	int n; Lista dist , iter;
    	vector< vector<AristaFlujo*> > aristas;
    	GrafoFlujo(int N) : n(N), aristas(N), dist(N), iter(N) {}
    	~GrafoFlujo(){
        	for(int i = 0; i < n; ++i)
            		for (int j = 0; j < aristas[i].size(); ++j)
                		delete aristas[i][j];
    	}
    	void AgregarArista(int u, int v, Flujo c, Costo p = 0){
        	AristaFlujo* uv = new AristaFlujo(v, 0, c);
       	 	AristaFlujo* vu = new AristaFlujo(u, c, c);
        	uv->residual = vu, vu->residual = uv;
        	aristas[u].push_back(uv);
        	aristas[v].push_back(vu);
    	}
    	Flujo FlujoBloqueante(int u, int t, Flujo f){
        	if(u == t)return f;
        	for(int &i = iter[u] ; i < aristas[u].size(); ++i){
            		AristaFlujo* v = aristas[u][i];
            		if(v -> cap - v -> flujo > 0 && dist[u] + 1 == dist[v->dst]){
                		Flujo fv = FlujoBloqueante(v->dst, t, min(f, v->cap - v->flujo));
                		if(fv > 0){
                    			v->AumentarFlujo(fv);
                    			return fv;
                		}
            		}
        	}
        	return 0;
    	}
    	Flujo Dinic(int s, int t) {
        	Flujo flujo_maximo = dist[t] = 0;
        	while(dist[t] < INT_MAX){
            		fill(dist.begin(), dist.end(), INT_MAX);
            		queue<int> q; q.push(s); dist[s] = 0;
            		while(!q.empty()){
                		int u = q.front(); q.pop();
                		for(int i = 0; i < aristas[u].size(); ++i){
                    			AristaFlujo* v = aristas[u][i];
                    			if(dist[v->dst] < INT_MAX) continue;
                    			if(v->flujo == v->cap) continue;
                    			dist[v->dst] = dist[u] + 1;
                    			q.push(v->dst);
                		}
            		}
            		if(dist[t] < INT_MAX){
                		Flujo fluido;
                		iter.assign(n, 0);
                		while((fluido = FlujoBloqueante(s, t, INF)) != 0)
                    			flujo_maximo += fluido;
            		}
        	}
		return flujo_maximo;
    	}
};
int t,n;
float d;
vector< pair<ff,int> > in;
int main(){
	//optimizar_io;
	cin >> t;
	while(t--){
		cin >> n >> d;
		GrafoFlujo flujo(2*n+1);
		for(int i = 1; i <= n;  i++){
			flujo.AgregarArista(0,2*i-1,10000000);
		}
		for(int i = 0; i < n; i++){
			float x,y; int c;
			cin >> x >> y >> c;
			in.push_back({{x,y},c});
			flujo.AgregarArista(2*(i+1)-1,2*(i+1),c);
		}
		for(int i = 0; i < in.size(); i++){
			for(int j = 0; j < in.size(); j++){
				float dist = hypot(in[i].first-in[j].first,in[i].second-in[j].second);
				if(dist <= d){
					flujo.AgregarArista(2*(i+1),2*(j+1)-1,1<<20);
					flujo.AgregarArista(2*(j+1),2*(i+1)-1,1<<20);

				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				flujo.AgregarArista(2);
			}
		}

	}
}

