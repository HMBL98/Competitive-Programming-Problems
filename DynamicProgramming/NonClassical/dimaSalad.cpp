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

const int inf = 1<<29;
#define MAX 100+10
int n,k,t[MAX],c[MAX],memo[MAX][50000];

int dp(int pos,int tot){
	if(pos == n)return !tot ? 0 : -inf;
	int &res = memo[pos][tot+20000];
	if(res != -1)return res;
	res = -inf;
	res = max(res,t[pos]+dp(pos+1,tot+t[pos]-c[pos]));
	res = max(res,dp(pos+1,tot));
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,MAX)forn(j,0,50000)memo[i][j] = -1;
	cin >> n >> k;
	forn(i,0,n)cin >> t[i];
	forn(i,0,n)cin >> c[i],c[i] *= k;
	int res = dp(0,0);
	if(!res)cout << "-1\n";
	else cout << res << "\n";
}
