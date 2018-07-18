#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100+10
typedef long long ll;
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
int T,ncase;
ll s1[MAX],s2[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--){
		int n,m;
		cin >> n;
		graph.assign(n,vi());
		forn(i,0,n) cin >> s1[i];
		cin >> m;
		forn(i,0,m) cin >> s2[i];
		forn(i,0,n){
			forn(j,0,m){
				if(s1[i] != 0 && s2[j]%s1[i] == 0){
					//cout << s1[i] << " " << s2[j] << "\n";
					graph[i].push_back(j);
				}
				if(s2[j] == 0)graph[i].push_back(j);
			}
		}
		cout << "Case " << ++ncase << ": " << kuhn(n,m) << "\n";
	}
  	return 0;
}
