#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,n) for (int i=a;i<n;i++)

#define MAXN 100+10
#define MAXM 500+10

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;

ll dist[MAXN][MAXM];
ll cost[MAXN][MAXM];
ii p[MAXN][MAXM];
int movX[] = {0,0,1};
int movY[] = {-1,1,0};

int n,m;
bool possible(int i,int j){
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return true;
}
vector<int> res;
void path(ii u){
	if(u == p[u.first][u.second]) res.push_back(u.second);
	else{
		res.push_back(u.second);
		path(p[u.first][u.second]);
	}
}

int main(){
	cin >> n >> m;
	forr(i,0,n)forr(j,0,m)cin >> cost[i][j];

	forr(i,0,n+5)forr(j,0,m+5) dist[i][j] = 1LL<<60;
     	priority_queue< iii, vector<iii>, greater<iii> > pq;
	forr(i,0,m){
		dist[0][i] = cost[0][i];
		p[0][i] = ii(0,i);
		pq.push(iii(cost[0][i],ii(0,i)));
	}
        while(!pq.empty()){
        	iii act = pq.top(); pq.pop();
                ll d = act.first; ii u = act.second;
                if(d > dist[u.first][u.second]) continue;
		forr(i,0,3){
			if(possible(u.first+movX[i],u.second+movY[i])){
				if(dist[u.first][u.second]+cost[u.first+movX[i]][u.second+movY[i]] < dist[u.first+movX[i]][u.second+movY[i]]){
					p[u.first+movX[i]][u.second+movY[i]] = ii(u.first,u.second);
					dist[u.first+movX[i]][u.second+movY[i]] = dist[u.first][u.second]+cost[u.first+movX[i]][u.second+movY[i]];
					pq.push(iii(dist[u.first+movX[i]][u.second+movY[i]],ii(u.first+movX[i],u.second+movY[i])));
				}
			}
                }
       	}
	ll mini = 1LL<<60;
	int d1;
	forr(i,0,m){
		if(dist[n-1][i] < mini){
			mini = dist[n-1][i];
			d1 = i;
		}
	}
	path(ii(n-1,d1));
	reverse(res.begin(),res.end());
	forr(i,0,res.size()){
		if(i) cout << " ";
		cout << res[i]+1;
	}
	cout << "\n";
}
