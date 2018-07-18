#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
} 
bool isPrime(ll n){
	if(n <= _sieve_size) return bs[n];
	for(int i = 0; i < (int)primes.size(); i++)
		if(n%primes[i] == 0) return false;
	return true;
} //only work for N <= (last prime in vi "primes")^2

vi primeFactors(ll n){
	vi factors;
	ll pf_idx = 0, pf = primes[pf_idx];
	int ans = 0;
	while(pf*pf <= n){
		while(n%pf == 0){ n /= pf; ans++; factors.push_back(pf);}
		pf = primes[++pf_idx];
	}
	if(n != 1){
		factors.push_back(n);
		ans++;
	}
	//return ans Number of prime factors of n
	return factors;
} //s142391208960LL = 2^10*3^4*5*7^4*11*13
/*Faster prime factors log(n)
bool bs[MAX];
ll sp[MAX];
void sieve(){
        for(int i = 2; i < MAX; i += 2)sp[i] = 2;//even numbers have smallest prime factor 2
        for(ll i = 3; i < MAX; i += 2){
                if(!bs[i]){
                        sp[i] = i;
                        for(ll j = i; (j*i) < MAX; j += 2){
                                if(!bs[j*i])bs[j*i] = true, sp[j*i] = i;
                        }
                }
        }
}
void primeFactors(ll x){
        cout << x << " -> ";
        while(x != 1){
                cout << sp[x] << " ";
                x = x/sp[x];
        }
        cout << "\n";
}
*/
ll numDiv(ll n){
	ll pf_idx = 0, pf = primes[pf_idx],ans = 1;
	while(pf*pf <= n){
		ll power = 0;
		while(n%pf == 0){ n /= pf; power++;}
		ans *= (power+1);
		pf = primes[++pf_idx];
	}
	if(n != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
	return ans;
}
ll sumDiv(ll n){
	ll pf_idx = 0, pf = primes[pf_idx], ans = 1;
	while(pf*pf <= n){
		ll power = 0;
		while(n%pf == 0){ n /= pf; power++; }
		ans *= ((ll)pow((double)pf,power+1.0)-1)/(pf-1);
		pf = primes[++pf_idx];
	}
	if(n != 1) ans *= ((ll)pow((double)n,2.0)-1)/(n-1);
	return ans;
} // 60 = 180

ll eulerPhi(ll n){
	ll pf_idx = 0, pf = primes[pf_idx], ans = n;
	while(pf*pf <= n){
		if(n%pf == 0) ans -= ans/pf;
		while(n%pf == 0) n /= pf;
		pf = primes[++pf_idx];
	}
	if(n != 1) ans -= ans/n;
	return ans;
}
int gcd(int a,int b){ return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){ return a*(b/gcd(a,b));}

int x,y,d;
void extEuclides(int a,int b){
	if(b == 0){ x = 1; y = 0; d = a; return;}
	extEuclides(b,a%b);
	int x1 = y;
	int y1 = x-(a/b)*y;
	x = x1;
	y = y1;
}

int power(int a,int b,int m){
	int res = 1;
	//a = a%m;
	while(b){
		if(b&1) res = (a*res)%m;
		b >>= 1;
		a = ((a%m)*(a%m))%m;
	}
	return res;
}
// A^B^C mod M Fermat little theorem
int calculate(int a,int b,int c,int m){
	int res,ans;
	res = power(b,c,m-1);
	ans = power(a,res,m);
	return ans;
}
// Luca's theorem Compute nCr % p 

// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModp(int n,int r,int p){
	int C[r+1];
	memset(C,0,sizeof(C));
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i,r); j > 0; j--){
			C[j] = (C[j]+C[j-1])%p;
		}
	}
	return C[r];
}
// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n,int r,int p){
	if(r == 0) return 1;
	int ni = n%p, ri = r%p;
	return (nCrModpLucas(n/p,r/p,p)*nCrModp(ni,ri,p))%p;
}
// Chinese Remainder Theorem

// Returns modulo inverse of a with respect to m using extended
int inv(int a,int m){
	int m0 = m, t,q;
	int x0 = 0, x1 = 1;
	if(m == 1)return 0;
	while(a > 1){
		q = a/m;
		t = m;
		m = a%m, a = t;
		t = x0;
		x0 = x1-q*x0;
		x1 = t;
	}
	if(x1 < 0) x1 += m0;
	return x1;
}
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k){
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}
//Wilson’s Theorem
// Function to find modular inverse of a under modulo p
// using Fermat's method. Assumption: p is prime
int modInverse(int a, int p){
   return power(a, p-2, p);
}
// Returns n! % p using Wilson's Theorem
int modFact(int n, int p){
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;
 
    // Initialize result as (p-1)! which is -1 or (p-1)
    int res = (p-1);
 
    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (int i=n+1; i<p; i++)
       res  = (res * modInverse(i, p)) % p;
    return res;
}
bool isPerfect(int n){
	int sum = 1;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) sum = sum+i+n/i;
	}
	if(sum == n && n != 1) return true;
	return false;
}
ll n,p;
ll tmp[100000];
int main(){
	cin >> n;
	sieve(1000000);
	//cout << primes.size() << "\n";
	//for(int i = 0; i < primes.size(); i++) cout << primes[i] << "\n";
	/*while(cin >> n){
		cout << isPerfect(n) << "\n";
	}*/
	tmp[1] = 1;
	ll maxi = -1;
	for(int i = 2; i <= n; i++){
		tmp[i] += tmp[i-1]+eulerPhi(i);
		if(tmp[i]-1 <= 100000){
			cout << i << " " << tmp[i]-1 << "\n";
			maxi = max(maxi,tmp[i]-1);
		}
	}
	cout << "\n" <<  maxi << "\n";
}

