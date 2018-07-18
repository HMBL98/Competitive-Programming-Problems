#include <bits/stdc++.h>
using namespace std;

#define MAX 100

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

/*** Example Usage and Output:

Matched 3 pair(s):
1 0
0 1
2 2

***/

int main(){
	int n1 = 3, n2 = 4;
	graph.assign(n1,vi());
  	graph[0].push_back(1);
  	graph[1].push_back(0);
  	graph[1].push_back(1);
  	graph[1].push_back(2);
  	graph[2].push_back(2);
  	graph[2].push_back(3);
  	cout << "Matched " << kuhn(n1, n2) << " pair(s):" << endl;
  	for(int i = 0; i < n2; i++){
    		if(match[i] != -1){
      			cout << match[i] << " " << i << endl;
    		}
  	}
  	return 0;
}
