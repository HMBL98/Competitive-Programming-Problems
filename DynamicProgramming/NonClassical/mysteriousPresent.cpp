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

#define MAX 5000+10
vector< pair<ii,int> > env;
vector< pair<ii,int> > ans;
const ll inf = 1ll<<50;
ll dp[MAX];
int idx[MAX];

int n,w,h;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> w >> h;
	env.pb({{w,h},0});
	forn(i,0,n){
		cin >> w >> h;
		if(env[0].fi.fi < w && env[0].fi.se < h)env.pb({{w,h},i});
	}
	sort(env.begin(),env.end());
	forn(i,1,env.size()){
		forr(j,i-1,0){
			if(env[j].fi.fi < env[i].fi.fi && env[j].fi.se < env[i].fi.se && dp[j]+1 > dp[i]){
				dp[i] = dp[j]+1;
				idx[i] = j;
			}
		}
	}
	int maxi = 0;
	int pos = 0;
	forn(i,1,env.size())
		if(dp[i] > maxi){
			maxi = dp[i];
			pos = i;
		}
	while(1){
		if(pos == 0)break;
		ans.push_back(env[pos]);
		pos = idx[pos];
	}
	sort(ans.begin(),ans.end());
	cout << maxi << "\n";
	if(maxi)for(auto &x : ans) cout << x.se+1 << " ";
}

