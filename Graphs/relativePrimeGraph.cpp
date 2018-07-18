//D. Relatively Prime Graph
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll n,m,edges;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,1,ll(min(n+1,600ll)))
		forn(j,i+1,ll(min(n+1,600ll)))
			if(__gcd(i,j) == 1)edges++;
	if(m > edges || m < n-1)cout << "Impossible\n";
	else{
		cout << "Possible\n";
		forn(i,2,n+1){
			cout << 1 << " " << i << "\n";
			m--;
		}
		if(m){
			forn(i,2,ll(min(n+1,600ll)))
        	        	forn(j,i+1,ll(min(n+1,600ll)))
                	        	if(__gcd(i,j) == 1){
						cout << i << " " << j << "\n";
						m--;
						if(!m)return 0;
					}
		}
	}
	return 0;
}
