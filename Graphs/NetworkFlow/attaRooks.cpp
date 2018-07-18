#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 100+10
#define MAXV 5000

typedef vector<int> vi;
int match[MAXV],seen[MAXV];
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> col;
char grid[MAXN][MAXN];
int N;

int main(){
	optimizar_io;
	while(cin >> N){
		int set1 = 0,set2 = 0;
		for(int i = 0; i < N; i++)for(int j = 0; j < N; j++) cin >> grid[i][j];
		col.assign(N,vii());
		graph.assign(MAXV,vi());
		for(int i = 0; i < N; i++){
			int ant = 0;
			bool point = false;
			for(int j = 0; j < N; j++){
				if(grid[j][i] == 'X' && point){
					col[i].push_back({ant,j-1});
					point = false;
					set2++;
				}
				if(grid[j][i] == '.' && !point){
					if(j == N-1) set2++;
					ant = j;
					point = true;
				}
			}
			if(point){
				col[i].push_back({ant,N-1});
				set2++;
			}
		}
		for(int i = 0; i < N; i++){
			bool point = false;
			for(int j = 0; j < N; j++){
				if(grid[i][j] == 'X' && point){
					set1++;
					point = false;
				}
				if(grid[i][j] == '.' && !point){
					point = true;
				}
				if(grid[i][j] == '.'){
					int counter2 = 0;
                                        for(int k = 0; k < j; k++) counter2 += col[k].size();
                                        for(int k = 0; k < col[j].size(); k++){
                                                if(col[j][k].first <= i && i <= col[j][k].second){
                                                        //cout << set1 << " " << counter2+k << "\n";
							graph[set1].push_back(counter2+k);
                                                }
                                        }

				}
			}
			if(point)set1++;
		}
		cout << kuhn(set1,set2) << "\n";
	}
}
