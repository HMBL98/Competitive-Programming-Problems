#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 1000+100
char grid[MAX][MAX];
int t,n,m,dist[MAX][MAX][5];
int _x[] = {-1,0,0,1};
int _y[] = {0,-1,1,0};

bool can(int i,int j){
	if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')return false;
	return true;
}
const int inf = 1<<20;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		int s1,s2;
		int d1,d2;
		forn(i,0,n)
			forn(j,0,m){
				cin >> grid[i][j];
				if(grid[i][j] == 'J'){
					s1 = i; s2 = j;
				}else if(grid[i][j] == 'E'){
					d1 = i; d2 = j;
				}
			}
		forn(i,0,n+10)forn(j,0,m+10)forn(k,0,5)dist[i][j][k] = inf;
		queue< pair<ii,int>  > q;
		dist[s1][s2][0] = 0;
		for(q.push({{s1,s2},0}); !q.empty(); q.pop()){
			pair<ii,int> act = q.front();
			forn(i,0,4){
				int n1 = act.fi.fi+_y[i];
				int n2 = act.fi.se+_x[i];
				int n3 = act.se;
				if(can(n1,n2)){
					if(grid[n1][n2] == 'F') n3 |= 1<<0;
					if(grid[n1][n2] == 'K') n3 |= 1<<1;
					if(dist[n1][n2][n3] == inf){
						dist[n1][n2][n3] = dist[act.fi.fi][act.fi.se][act.se]+1;
						pair<ii,int> nue = {{n1,n2},n3};
						q.push(nue);
					}
				}
			}
		}
		cout << dist[d1][d2][3] << "\n";
	}
}
