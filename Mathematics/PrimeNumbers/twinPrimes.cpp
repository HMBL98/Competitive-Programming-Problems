#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef vector<ll> vll;
bitset<20000000> bs;
ll sieve_size;
vll primes;

void sieve(ll upperbound){
	sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
ll n;
vector< pair<ll,ll> > res;
int main(){
	optimizar_io;
	sieve(20000000-10);
	for(int i = 1; i < primes.size(); i++){
		if(primes[i]-2 == primes[i-1]) res.push_back({primes[i-1],primes[i]});
	}
	while(cin >> n){
		cout << "(" << res[n-1].first << ", " << res[n-1].second << ")\n";
	}	
}
