//11492 - Babel
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef pair<int,string> is;
typedef vector<is> vis;
typedef pair<int,is> iis;

vector<vis> grafo;

map<string,int> mapper;
int n,idx,x,y,dist[100000];


int main(){
	optimizar_io;
	while(cin >> n,n){
		string u,v,word;
		cin >> u >> v; idx = 3;
		mapper[u] = 1;
		mapper[v] = 2;
		grafo.assign(100000,vis());
		for(int i = 0; i < n; i++){
			cin >> u >> v >> word;
			if(!mapper[u]){
				x = idx;
				mapper[u] = x;
				idx++;
			}else x = mapper[u];
			if(!mapper[v]){
				y = idx;
				mapper[v] = y;
				idx++;
			}else y = mapper[v];
			grafo[x].push_back({y,word});
			grafo[y].push_back({x,word});
		}
		int res1,res2;

		for(int i = 0; i < 100000; i++)dist[i] = 1<<20;
		priority_queue< iis, vector<iis>, greater<iis> >  pq; pq.push(iis(0,{1,""}));
		dist[1] = 0;
		while(!pq.empty()){
			iis act = pq.top(); pq.pop();
			int d = act.first, u = act.second.first;
			string anterior = act.second.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < grafo[u].size(); i++){
				if(dist[u]+grafo[u][i].second.size() < dist[grafo[u][i].first] && anterior[0] != grafo[u][i].second[0]){
					dist[grafo[u][i].first] = dist[u]+grafo[u][i].second.size();
					pq.push(iis(dist[grafo[u][i].first],{grafo[u][i].first,grafo[u][i].second}));
				}
			}
		}
		res1 = dist[2];

		for(int i = 0; i < 100000; i++)dist[i] = 1<<20;
                priority_queue< iis, vector<iis>, greater<iis> >  pq1; pq1.push(iis(0,{2,""}));
                dist[2] = 0; 
                while(!pq1.empty()){
                        iis act = pq1.top(); pq1.pop();
                        int d = act.first, u = act.second.first;
                        string anterior = act.second.second;
                        if(d > dist[u]) continue;
                        for(int i = 0; i < grafo[u].size(); i++){
                                if(dist[u]+grafo[u][i].second.size() < dist[grafo[u][i].first] && anterior[0] != grafo[u][i].second[0]){
                                        dist[grafo[u][i].first] = dist[u]+grafo[u][i].second.size();
                                        pq1.push(iis(dist[grafo[u][i].first],{grafo[u][i].first,grafo[u][i].second}));
                                }
                        }
                }
                res2 = dist[1];

		int res = min(res1,res2);

		if(res == 1<<20) cout << "impossivel" << endl;
		else cout << res << endl;
		mapper.clear();
	}
}
