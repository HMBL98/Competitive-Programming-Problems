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
int n,m,vh[MAX],vm[MAX];
int main(){
	optimizar_io;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> vh[i];
	cin >> m;
	for(int i = 0; i < m; i++) cin >> vm[i];
	graph.assign(n,vi());
	for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)
		if(abs(vh[i]-vm[j]) <= 1){
			graph[i].push_back(j);
		}
	cout << kuhn(n,m) << "\n";
}
