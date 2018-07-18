//C. Bear and Prime Numbers codeforces
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 10000000+10
typedef long long ll;
ll fp[MAX],N,M;

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
	ll ant = -1;
        while(x != 1){
		if(sp[x] != ant){
			fp[sp[x]]++;
			ant = sp[x];
		}
                x = x/sp[x];
        }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	cin >> N;
	forn(i,0,N){
		ll tmp; cin >> tmp;
		primeFactors(tmp);

	}
	forn(i,1,MAX)fp[i] += fp[i-1];
	cin >> M;
	while(M--){
		ll l,r; cin >> l >> r;
		if(r > MAX) r = MAX-1;
		if(l > MAX) l = MAX-1;
		cout << fp[r]-fp[l-1] << "\n";
	}
}
