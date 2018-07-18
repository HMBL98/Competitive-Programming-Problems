#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 50+10

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
int match[MAX],seen[MAX],capacity[MAX];
vector<vi> graph;
vector<vi> vault;
vector<ii> info;

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
	sort(info.begin(),info.end());
  	for(int i = info.size()-1; i >= 0; i--){
		int u = info[i].second;
    		fill(seen,seen+n1,0);
    		if(dfs(u))matches++;
  	}
  	return matches;
}

vector<ll> X,Y;
void computeSubArray(bool left,int t,int idx,int no){
	for(int i = 0; i < (1<<t); i++){
		ll sum = 0;
		for(int j = 0; j < t; j++)
			if(i&(1<<j)) sum += vault[no][j+idx];
		if(left) X.push_back(sum);
		else Y.push_back(sum);
	}
}
bool possible(int w){
	for(int i = 0; i < X.size(); i++){
		ll ini = 0, fin = Y.size()-1;
		while(ini <= fin){
			ll mit = (ini+fin)>> 1;
			if(X[i]+Y[mit] == w)return true;
			else if(X[i]+Y[mit] < w){
				ini = mit+1;
			}else{
				fin = mit-1;
			}
		}
	}
	return false;
}
int T,N,M;

int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		cin >> N >> M;
		graph.assign(N,vi());
		vault.assign(M,vi());
		for(int i = 0; i < N; i++){
			int w; cin >> w;
			info.push_back({w,i});
			capacity[i] = w;
		}
		for(int i = 0; i < M; i++){
			int c,tmp; cin >> c;
			for(int j = 0; j < c; j++){
				cin >> tmp;
				vault[i].push_back(tmp);
			}
		}
		for(int i = 0; i < M; i++){
			X.clear(); Y.clear();
			computeSubArray(true,vault[i].size()/2,0,i);
			computeSubArray(false,vault[i].size()-vault[i].size()/2,vault[i].size()/2,i);
			/*for(int j = 0; j < X.size(); j++) cout << X[j] << " ";
			cout << "\n";
			for(int j = 0; j < Y.size(); j++) cout << Y[j] << " ";
			cout << "\n";*/
			sort(Y.begin(),Y.end());
			for(int j = 0; j < N; j++){
				if(possible(capacity[j])){
					//cout << "_____" << j+1 << " " << i+1 << "\n";
					graph[j].push_back(i);
				}
			}
		}
		int matches = kuhn(N,M);
		ll res = 0;
	  	for(int i = 0; i < M; i++){
    			if(match[i] != -1){
				res += capacity[match[i]];
    			}
  		}
		cout << res << "\n";
		info.clear();
	}
  	return 0;
}
