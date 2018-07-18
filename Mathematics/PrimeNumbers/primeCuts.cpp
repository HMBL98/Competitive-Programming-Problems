#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll sieve_size;
bitset<10000010> bs;
vll primes;

// 2 3 5 7 11 13 17 
void sieve(ll upperbound){
	primes.push_back(1);
	sieve_size = upperbound;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
int n,c,caso;
int main(){
	while(cin >> n >> c){
		sieve(n);
		cout << n << " " << c << ": ";
		if(primes.size()%2 == 0 && 2*c <= primes.size()){
			int cuantos = primes.size()-2*c;
			cuantos /= 2;
			for(int i = 0; i < 2*c; i++){
				if(i) cout << " ";
				cout << primes[cuantos++];
			}
			cout << "\n";
		}else if(primes.size()%2 != 0 && 2*c-1 <= primes.size()){
			int cuantos = primes.size()-(2*c-1);
			cuantos /= 2;
			for(int i = 0; i < 2*c-1; i++){
				if(i) cout << " ";
				cout << primes[cuantos++];
			}
			cout << "\n";
		}else{
			for(int i = 0; i < primes.size(); i++){	
				if(i) cout << " ";
				cout << primes[i];
			}
			cout << "\n";
		}
		primes.clear();
		cout << "\n";
	}
}
