#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 5000+10
int n,w,h;
pair<ii,int> env[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> w >> h;
	forn(i,0,n){
		cin >> env[i].fi.fi >> env[i].fi.se;
		env[i].se = i;
	}
	sort(env,env+n);
	int dp[MAX];
}
