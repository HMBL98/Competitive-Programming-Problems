//10977 - Enchanted Forest
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 200+10
int R,C,M,N;
typedef pair<int,int> ii;

int mvX[] = {-1,0,0,1};
int mvY[] = {0,-1,1,0};

struct info{
	int x,y,l;
};
info gly[MAX];
int dist[MAX][MAX];
const int inf = 1<<20;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> R >> C,(R||C)){
		set<ii> points;
		cin >> M;
		while(M--){
			int x,y; cin >> y >> x;
			y--; x--;
			points.insert(ii(y,x));
		}
		cin >> N;
		forn(i,0,N){
			cin >> gly[i].y >> gly[i].x >> gly[i].l;
			gly[i].y--, gly[i].x--;
		}
		function<int(int,int)> possible = [&](int y,int x){
			if(y < 0 || y >= R || x < 0 || x >= C || points.find(ii(y,x)) != points.end()) return 0;
			if(dist[y][x] != inf) return 0;
			forn(i,0,N){
				double dist = hypot(y-gly[i].y,x-gly[i].x);
				//cout << dist << "\n";
				if(dist <= double(gly[i].l)) return 0;
			}
			return 1;
		};
		queue<ii> q; q.push(ii(0,0));
		forn(i,0,R)forn(j,0,C) dist[i][j] = inf;
		dist[0][0] = 0;
		while(!q.empty()){
			ii u = q.front(); q.pop();
			//cout << u.first << " " << u.second << "\n";
			forn(i,0,4){
				if(possible(u.first+mvY[i],u.second+mvX[i])){
					//cout << "\t" << u.first+mvY[i] << " " <<  u.second+mvX[i] << "\n";
					q.push(ii(u.first+mvY[i],u.second+mvX[i]));
					dist[u.first+mvY[i]][u.second+mvX[i]] = dist[u.first][u.second]+1;
				}
			}
		}
		if(dist[R-1][C-1] == inf) cout << "Impossible.\n";
		else cout << dist[R-1][C-1] << "\n";
	}
}
