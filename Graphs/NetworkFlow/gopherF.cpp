#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 500

typedef vector<int> vi;
int match[MAX],seen[MAX];
vector<vi> graph;

bool dfs(int u){
	if(seen[u]) return false;
	seen[u] = 1;
  	for(int i = 0; i < (int)graph[u].size(); i++){
    		int v = match[graph[u][i]];
    		if(v == -1 || dfs(v)){
      			match[graph[u][i]] = u;
      			return true;
    		}
  	}
  	return false;
}
/*int kuhn(int n1,int n2){
        fill(match,match+n2,-1);
        fill(seen,seen+n1,0);
        vector<char> seen1(n1);
        int matches = 0;
        for(int i = 0; i < n1; i++)
                for(int j = 0; j < (int)graph[i].size(); j++)
                        if(match[graph[i][j]] == -1){
                                match[graph[i][j]] = i;
                                matches++;
                                seen1[i] = true;
                                break;
                        }
        for(int i = 0; i < n1; i++){
                if(seen1[i])continue;
                fill(seen,seen+n1,0);
                if(dfs(i))matches++;
        }
        return matches;
}*/
int kuhn(int n1, int n2){
	fill(seen,seen+n1,0);
	fill(match, match + n2, -1);
  	int matches = 0;
  	for(int i = 0; i < n1; i++){
    		fill(seen,seen+n1,0);
    		if(dfs(i))matches++;
  	}
  	return matches;
}
typedef pair<double,double> dd;
int N,M;
double S,V;
vector<dd> cor1;
vector<dd> cor2;
int main(){
	optimizar_io;
	while(cin >> N >> M >> S >> V){
		graph.assign(N,vi());
		cor1.assign(N,dd());
		cor2.assign(M,dd());
		for(int i = 0; i < N; i++){
			double x,y; cin >> x >> y;
			cor1[i] = {x,y};
		}
		for(int i = 0; i < M; i++){ 
                        double x,y; cin >> x >> y;
                       	cor2[i] = {x,y};
                }
		for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
			double y = cor2[j].second-cor1[i].second;
			double x = cor2[j].first-cor1[i].first;
			double dist = hypot(y,x);
			if((double)dist/V <= (double)S){
				graph[i].push_back(j);
			}
		}
		cout << N-kuhn(N,M) << "\n";
  	}
}
