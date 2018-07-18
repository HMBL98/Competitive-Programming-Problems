//B. Maximum Absurdity
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 200000+10
typedef long long ll;
int n,k;
ll memo[MAX][5],val[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,MAX)forn(j,0,5) memo[i][j] = -1;
	cin >> n >> k;
	forn(i,1,n+1){
		cin >> val[i];
		val[i] += val[i-1];
	}
	int res1 = -1,res2 = -1;
	function<ll(int,int)> dp = [&](int pos,int counter){
		if(counter == 2) return 0ll;
		if(pos+k-1 > n) return -1ll<<50;
		if(memo[pos][counter] != -1)return memo[pos][counter];
		ll tomar = val[pos+k-1]-val[pos-1]+dp(pos+k,counter+1);
		ll notomar = dp(pos+1,counter);
		memo[pos][counter] = (tomar > notomar) ? tomar : notomar;
		return memo[pos][counter];
	};
	/*function<void(int,int)> printS = [&](int pos,int counter){
		if(counter == 2)return;
		if(pos+k-1 > n) return;
		ll tomar = val[pos+k-1]-val[pos-1]+dp(pos+k,counter+1);
		ll notomar = dp(pos+1,counter);
		//cout << pos << " " << counter << "\n";
		if(tomar >= notomar){
			if(res1 != -1 && res2 == -1) res2 = pos;
			if(res1 == -1) res1 = pos;
			printS(pos+k,counter+1);
			return;
		}else printS(pos+1,counter);
	};*/
	ll res = dp(1,0);
	printS(1,0);
	cout << res1 << " " << res2 << "\n";
}
//0 3 9 10 11 17
