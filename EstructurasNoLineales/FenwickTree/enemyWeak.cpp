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

#define MAX 1000000+10
ll n,val[MAX],great[MAX],tmp[MAX],low[MAX],bit[MAX];

ll query(int idx){
	ll sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum;
}
void update(int idx,int val){
	while(idx < n+1){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	forn(i,0,n) cin >> val[i];
	forn(i,0,n) tmp[i] = val[i];
	sort(tmp,tmp+n);
	forn(i,0,n){
		val[i] = lower_bound(tmp,tmp+n,val[i])-tmp+1;
	}
	forn(i,0,n){
		great[i] = i-query(val[i]);
		update(val[i],1);
	}
	memset(bit,0,sizeof bit);
	forr(i,n-1,0){
		low[i] = query(val[i]-1);
		update(val[i],1);
	}
	ll res = 0;
	forn(i,0,n) res += low[i]*great[i];
	cout << res << "\n";
}
