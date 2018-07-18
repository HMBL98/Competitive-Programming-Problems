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

#define MAX 100+10

int w,h,c,grid[MAX][MAX];
pair<int,ii> in[10];

int cs(){
	forn(i,0,w)
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> w >>  h >> c;
	forn(i,0,c)cin >> in[i].fi >> in[i].se.fi >> in[i].se.se;
	int res = cs(0,0);
	if(res)cout << "Yes\n";
	else cout << "No\n";
}
