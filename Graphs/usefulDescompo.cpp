//C. Useful Decomposition
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+10
typedef vector<int> vi;
vi graph[MAX];
vi res[MAX];
int n;

void dfs(int u,int p,int i){
	res[i].push_back(u);
	forn(j,0,graph[u].size())
		if(graph[u][j] != p)dfs(graph[u][j],u,i);
}
int main(){
	cin >> n;
	forn(i,0,n-1){
		int u,v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int idx = -1;
	int mayor = -1;
	bool possible = true;

	forn(i,1,n+1){
		if((int)graph[i].size() != 1 && (int)graph[i].size() != 2){
			if(idx == -1){
				idx = i;
				mayor = (int)graph[i].size();
			}
			else possible = false;
		}
	}
	if(idx == -1){
		forn(i,1,n+1){
			if((int)graph[i].size() > mayor){
	                	idx = i;
        	                mayor = (int)graph[i].size();
			}
        	}
	}
	if(!possible){
		cout << "No\n";
	}else{
		cout << "Yes\n";
		cout << mayor << "\n";
		forn(i,0,mayor){
			res[i].push_back(idx);
			dfs(graph[idx][i],idx,i);
		}
		forn(i,0,mayor){
			cout << res[i][0] << " " << res[i][res[i].size()-1] << "\n";
		}
	}
}

