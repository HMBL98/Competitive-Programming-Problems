#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll res = 0;
	ll pot = 1;
	while(1){
		double tmp = n/(pot*2);
		if(tmp*pot*2+pot < n)tmp++;
		if(tmp == 0)break;
		//cout << tmp << " " << pot << "\n";
		res += tmp*pot;
		pot *= 2;
	}
	cout << res << "\n";
}
