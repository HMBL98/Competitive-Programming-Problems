#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define INF (1<<20)
typedef int Flujo;
typedef int Costo;
typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;

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
    	GrafoFlujo(int N) : n(N), aristas(N),dist(N), iter(N) {}
    	~GrafoFlujo(){
        	for(int i = 0; i < n; ++i){
            		for(int j = 0; j < aristas[i].size(); ++j){
                		delete aristas[i][j];
			}
		}
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
string line;
int main(){
	//optimizar_io;
	while(getline(cin,line)){
		stringstream ss(line);
		vector<string> in; string tmp;
		while(ss >> tmp)in.push_back(tmp);
		int res = 1<<20;
		while(1){
			int s,t; cin >> s >> t;
			GrafoFlujo flujo(in.size());
        	        for(int i = 0; i < in.size(); i++)for(int j = i+1; j < in.size(); j++){
                		flujo.AgregarArista(i,j,in[i][j]-'0');
                        	flujo.AgregarArista(j,i,in[j][i]-'0');
	                }
			/*for(int i = 0; i < in.size(); i++){
				for(int j = i+1; j < in.size(); j++){
					int tmp = flujo.Dinic(i,j);
					cout << i << " " << j << " " << tmp << "\n";
					//res = min(res,tmp);
				}
			}*/
			cout << flujo.Dinic(s,t) << "\n"; 
			//cout << res << "\n";
		}
	}
    	return 0;
}
