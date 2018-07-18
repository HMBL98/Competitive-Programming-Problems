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

int c1,c2,x,y;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c1 >> c2 >> x >> y;

	function<bool(ll)> can = [&](ll mit){
		ll tmp = (mit-mit/x)+(mit-mit/y)-(mit-((mit/x)+(mit/y)-(mit/(x*y))));
		if(c1+c2 > tmp)return false;
		if(c1 > (mit-mit/x) || c2 > (mit-mit/y))return false;
		return true;
	};
	ll ini = 0,fin = 1ll<<50;
	while(ini < fin){
		ll mit = (ini+fin)>>1;
		if(can(mit))fin = mit;
		else ini = mit+1;
	}
	cout << ini << "\n";
}
