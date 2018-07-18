#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;
int n,m;

ll exp(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (a*res)%mod;
		b >>= 1;
		a = ((a%mod)*(a%mod))%mod;
	}
	return res;
}

ll res(){
	if(n == 1) return m;
	else if(n == 2)return ((m%mod)*(m-1)%mod)%mod;
	else return ((m%mod)*((m-1)%mod)*exp(m-2,n-2))%mod;
}

int main(){
	cin >> n >> m;
	cout << res() << "\n";
}
