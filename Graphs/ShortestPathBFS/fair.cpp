//D. Fair codeforces
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+10

const int inf = 1<<20;
typedef vector<int> vi;
vi graph[MAX],good[MAX];
int n,m,k,s,val[MAX],dist[100+10][MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k >> s;
	forn(i,0,n){
		cin >> val[i];
		good[val[i]].push_back(i);
	}
	forn(i,0,m){
		int x,y; cin >> x >> y; x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	forn(i,1,k+1){
		forn(j,0,n) dist[i][j] = inf; queue<int> q;
		for(auto &u : good[i]){
			q.push(u);
			dist[i][u] = 0;
		}
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto &v : graph[u]){
				if(dist[i][u]+1 < dist[i][v]){
					dist[i][v] = dist[i][u]+1;
					q.push(v);
				}
			}
		}
		//forn(j,0,n) cout << dist[i][j] << " ";
		//cout << "\n";
	}
	forn(i,0,n){
		vi values;
		forn(j,1,k+1){
			values.push_back(dist[j][i]);
		}
		sort(values.begin(),values.end());
		int res = 0;
		forn(j,0,s) res += values[j];
		cout << res << " ";
	}
}
