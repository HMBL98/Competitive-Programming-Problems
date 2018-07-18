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

#define MAX 300+10
ll n,q,mat[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,0,n)forn(j,0,n)cin >> mat[i][j];
	cin >> q;
	ll u,v,c;
	while(q--){
		cin >> u >> v >> c; u--; v--;
		if(c < mat[u][v]){
			mat[u][v] = c;
			mat[v][u] = c;
			forn(k,0,2)
				forn(i,0,n)
					forn(j,0,n){
						ll act = (k == 0) ? u : v;
						mat[i][j] = min(mat[i][j],mat[i][act]+mat[act][j]);
					}
		}
		ll res = 0;
		forn(i,0,n)forn(j,0,n)res += mat[i][j];
		cout << res/2 << " ";
	}
}
