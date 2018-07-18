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

#define MAX 5000+10
ll n,k,q,val[MAX];
const ll inf = 1ll<<55;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	forn(i,0,n)cin >> val[i];

	cin >> q;
	while(q--){
		ll target,res = inf; cin >> target;
		for(ll i = 1; i <= k; i++){
			for(ll j = 0; j <= i; j++){
				int l = 0, r = n-1;
				while(l <= r){
					ll act = (j*val[l])+((i-j)*val[r]);
					if(act == target){
						/*cout << "\n";
						cout << val[l] << " " << val[r] << "\n";
						cout << j << " " << i-j << "\n\n";*/
						res = min(res,j+(i-j));
						break;
					}else if(act < target)l++;
					else r--;
				}
			}
		}
		if(res == inf)cout << "-1\n";
		else cout << res << "\n";
	}
}

