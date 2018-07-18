#include <bits/stdc++.h>
using namespace std;

// O(VE^2) Edmonds Karp’s algorithm
#define MAX 1000
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
ll res[MAX][MAX],res2[MAX][MAX],f;
int p[MAX],source,sink;
typedef vector<int> vi;
typedef pair<float,float> ff;
vector<vi> graph;

void augment(int v,ll minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		ll mini = (minEdge < res2[p[v]][v]) ? minEdge : res2[p[v]][v];
		augment(p[v],mini);
		res2[p[v]][v] -= f; res2[v][p[v]] += f;
	}
}
ll flow(){
	ll mf = 0;
        while(1){
                f = 0;
                for(int i = 0; i < MAX; i++) p[i] = -1;
                queue<int> q; q.push(source);
                while(!q.empty()){
                        int u = q.front(); q.pop();
                        if(u == sink) break;
                        for(int i = 0; i < graph[u].size(); i++){
                                int v = graph[u][i];
                                if(res2[u][v] > 0 && p[v] == -1){
                                        p[v] = u; q.push(v);
                                }
                        }
                }
                augment(sink,1<<20);
                if(f == 0)break;
                mf += f;
        }
	return mf;
}
int t,n;
float d;
vector< pair<ff,int> > in;
int main(){
        optimizar_io;
 	      cin >> t;
        while(t--){
                cin >> n >> d;
		graph.assign(2*n+1,vi());
		memset(res,0,sizeof res);
		int pingus = 0;
                for(int i = 1; i <= n; i++){
                        float x,y; int c1,c2;
                        cin >> x >> y >> c1 >> c2;
                        in.push_back({{x,y},c1});
			graph[2*i-1].push_back(2*i);
                        graph[2*i].push_back(2*i-1);
                        res[2*i-1][2*i] = c2;
                        res[2*i][2*i-1] = 0;
			//cout << 2*i-1 << " " << 2*i << "\n";
			pingus += c1;

                }
		for(int i = 1; i <= n;  i++){
                        graph[0].push_back(2*i-1);
                        graph[2*i-1].push_back(0);
                        res[0][2*i-1] = in[i-1].second;
                        res[2*i-1][0] = 0;
                        //cout << 0 << " " << 2*i-1 << "\n";
                }
                for(int i = 0; i < in.size(); i++){
                        for(int j = i+1; j < in.size(); j++){
                                float dist = hypot(in[i].first.first-in[j].first.first,in[i].first.second-in[j].first.second);
                                if(dist <= d){
					graph[2*(i+1)].push_back(2*(j+1)-1);
                        		graph[2*(j+1)-1].push_back(2*(i+1));
                        		res[2*(i+1)][2*(j+1)-1] = 1<<20;
                        		res[2*(j+1)-1][2*(i+1)] = 0;


					graph[2*(j+1)].push_back(2*(i+1)-1);
                                        graph[2*(i+1)-1].push_back(2*(j+1));
                                        res[2*(j+1)][2*(i+1)-1] = 1<<20;
                                        res[2*(i+1)-1][2*(j+1)] = 0;

					//cout << 2*(i+1) << " " << 2*(j+1)-1 << "\n";
					//cout << 2*(j+1) << " " << 2*(i+1)-1 << "\n";

                                }
                        }
                }
		int source = 0;
		vector<int> ans;
                for(int i = 1; i <= n; i++){
			sink = 2*i-1;
			for(int i = 0; i <= 2*n+1; i++)for(int j = 0; j <= 2*n+1; j++) res2[i][j] = res[i][j];
                        for(int j = 1; j <= n; j++){
				if(i != j){
					graph[2*j].push_back(2*i-1);
					graph[2*i-1].push_back(2*j);
					res[2*j][2*i-1] = 1<<20;
					res[2*i-1][2*j] = 0;
				}
                        }
			ll tmp = flow();
			if(tmp == pingus) ans.push_back(i-1);
			//cout << tmp << "\n";
			for(int j = 1; j <= n; j++){
				if(i != j){
					graph[2*j].pop_back();
					graph[2*i-1].pop_back();
				}
			}
                }
		//cout << "\n";
		if(ans.empty()) cout << "-1\n";
		else{
			for(int i = 0; i < ans.size(); i++){
				if(i)cout << " ";
				cout << ans[i];
			}
			cout << "\n";
		}
		in.clear();

        }
}

