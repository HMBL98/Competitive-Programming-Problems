#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 100000+10
ll cub[MAX],dp[MAX];
int n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,0,n){
		ll tmp; cin >> tmp;
		cub[tmp]++;
	}
	dp[1] = 1*cub[1];
	forn(i,2,MAX)dp[i] = max(dp[i-1],i*cub[i]+dp[i-2]);
	cout << dp[MAX-1] << "\n";
}
