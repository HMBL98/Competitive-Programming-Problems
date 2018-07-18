#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

typedef vector<int> vi;
vector<vi> graph(MAX);
int visitado[MAX];

int n,x,res;

void dfs(int n,int capa){
	visitado[n] = 1;
	for(int i = 0; i < graph[n].size(); i++){
		if(visitado[graph[n][i]] == -1){
			if(capa+1 == x) res++;
			dfs(graph[n][i],capa+1);
		}
	}
}
int main(){
	memset(visitado,-1,sizeof visitado);
	cin >> n;
	for(int i = 1; i < n; i++){
		int s,d; cin >> s >> d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	cin >> x;
	res = 0;
	dfs(1,1);
	if(x == 1) cout << 1 << endl;
	else cout << res << endl;
}
