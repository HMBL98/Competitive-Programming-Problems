//https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
//https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
#include <bits/stdc++.h>
using namespace std;

#define MAX 2*100000+10
#define MOD 1000000007

typedef long long ll;

/*ll C[MAX+1];
ll binomialCoeff(int n,int k){
	C[0] = 1; // nC0 is 1
	for(int i = 1; i <= n; i++){
			// Compute next row of pascal triangle using
		        // the previous row
			for(int j = min(i,k); j > 0; j--) C[j] = (C[j]%MOD+C[j-1]%MOD)%MOD;
	}
	return C[k];
}*/
ll gcdE(ll a,ll b,ll *x, ll *y){
	if(a == 0){
		*x = 0, *y = 1;
		return b;
	}
	ll x1,y1;
	ll gcd = gcdE(b%a,a,&x1,&y1);
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}
ll modInverse(ll b,ll m){
	ll x,y;
	ll g = gcdE(b,m,&x,&y);
	if(g != 1) return -1;
	return (x%MOD+MOD)%MOD;
}
ll modDivide(ll a,ll b){
	a = a%MOD;
	ll inv = modInverse(b,MOD);
	if(inv == -1) return -1;
	return (inv*a)%MOD;
}
ll binomialCoeff(int n,int k){
	ll res = 1;
	if(k > n-k) k = n-k;
	for(int i = 0; i < k; i++){
		res = (res%MOD*(n-i)%MOD)%MOD;
		res = modDivide(res,i+1);
	}
	return res;
}
int n;

int main(){
	cin >> n;
	ll res = binomialCoeff(n+n-1,n);
	res = (res%MOD+res%MOD)%MOD;
	res = (res%MOD-n%MOD)%MOD;
	cout << res << "\n";
}

