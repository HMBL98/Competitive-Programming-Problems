#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> dd;
typedef pair<int,double> id;
typedef vector<id> vid;

vector<vid> grafo;
vector<dd> coor;
vector<double> dist;

int n;
double w,h;
double limite;
string linea;


int main(){
	while(getline(cin,linea)){
		if(linea[0] == '*')break;
		stringstream ss(linea);
		ss >> w >> h;
		cin >> n;

		grafo.assign(n+2,vid());

		coor.push_back({0,0});
		for(int i = 0; i < n; i++){
			double x,y; cin >> x >> y;
			coor.push_back({x,y});
		}
		coor.push_back({w,h});
		cin >> limite;

		for(int i = 0; i < coor.size(); i++)for(int j = i+1; j < coor.size(); j++){
			double distance = hypot(coor[j].first-coor[i].first,coor[j].second-coor[i].second);
			if(distance <= 1.5){
				grafo[i].push_back({j,distance});
				grafo[j].push_back({i,distance});
			}
		}
		dist.assign(n+2,1<<20); dist[0] = 0;
		priority_queue<id> pq; pq.push(id(0,0));
		while(!pq.empty()){
			id ac = pq.top(); pq.pop();
			double d = ac.first;
			int u = ac.second;
			if(d > dist[u])continue;
			for(int i = 0; i < grafo[u].size(); i++){
				id v = grafo[u][i];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(id(dist[v.first],v.first));
				}
			}
		}
		if(dist[n+1] <= limite) cout << "I am lucky!\n";
		else cout << "Boom!\n";
		cin.clear();
		cin.ignore();
		coor.clear();
	}
}
