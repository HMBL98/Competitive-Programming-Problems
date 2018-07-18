#include <bits/stdc++.h>
using namespace std;


#define MAXV 5000+10

typedef vector<int> vi;
vector<vi> graph;

int low[MAXV],num[MAXV],seen[MAXV],counter;
vi res,S;

int dfs(int u){
	low[u] = num[u] = counter++;
	S.push_back(u);
	seen[u] = 1;
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(num[v] == -1) dfs(v);
		if(seen[v]) low[u] = min(low[u],low[v]);
	}
	if(low[u] == num[u]){
		vi tmp;
		set<int> tmp2;
		while(1){
			int v = S.back(); S.pop_back(); seen[v] = 0;
			tmp.push_back(v);
			tmp2.insert(v);
			if(u == v)break;
		}
		bool status = true;
		for(int i = 0; i < tmp.size(); i++){
			for(int j = 0; j < graph[tmp[i]].size(); j++){
				int v = graph[tmp[i]][j];
				if(tmp2.find(v) == tmp2.end()) status = false;
			}
		}
		if(status){
			for(int i = 0; i < tmp.size(); i++) res.push_back(tmp[i]);
		}
	}
}



int v,e,x,y;

int main(){
	while(cin >> v,v){
		cin >> e;
		graph.assign(v+1,vi());
		memset(low,0,sizeof low);
		memset(num,-1,sizeof num);
		memset(seen,-1,sizeof seen);
		for(int i = 0; i < e; i++){
			cin >> x >> y;
			graph[x].push_back(y);
		}
		for(int i = 1; i <= v; i++)if(num[i] == -1)dfs(i);
		if(res.size() == 0) cout << "\n";
		else{
			sort(res.begin(),res.end());
			for(int i = 0; i < res.size(); i++){
				if(i)cout << " ";
				cout << res[i];
			}
			cout << "\n";
		}
		res.clear();
	}
}
