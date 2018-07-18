#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 1000000+10
int b[MAX];
int cub[MAX];
void pre(string p){
	int i = 0, j = -1; b[0] = -1;
	while(i < p.size()){
		while(j >= 0 && p[i] != p[j])j = b[j];
		i++; j++;
		b[i] = j;
	}
}
ll exp(ll a,ll b,ll c){
	ll res = 1;
	while(b){
		if(b&1) res = (a*res)%c;
		b >>= 1;
		a = ((a%c)*(a%c))%c;
	}
	return res;
}

ll n,m;
string str;
vi pos;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> str;
	pos.assign(m,0);

	forn(i,0,m)cin >> pos[i];
	sort(all(pos));

	pre(str);

	/*forn(i,0,str.size()+1)cout << b[i] << " ";
	cout << "\n";*/

	int act = b[str.size()];
	while(1){
		if(act == 0)break;
		cub[str.size()-act] = 1;
		act = b[act];
	}
	ll res = n;
	bool status = true;
	forn(i,0,m){
		if(i == 0){
			res -= str.size();
		}else{
			ll dif = pos[i]-pos[i-1];
			if(pos[i] == pos[i-1])continue;
			if(dif >= str.size())res -= str.size();
			else{
				if(cub[dif]){
					res -= dif;
				}else{
					status = false;
					break;
				}
			}
		}
	}
	if(!status)cout << "0\n";
	else{
		cout << exp(26,res,1000000007) << "\n";
	}
}

