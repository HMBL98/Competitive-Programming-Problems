//B. Petr and Permutations
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define MAX 1000000+10
typedef long long ll;
ll bit[MAX],val[MAX];

ll N;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	forn(i,0,N) cin >> val[i];
	function<void(int,int)> update = [&](int idx,int v){
		while(idx < MAX){
			bit[idx] += v;
			idx += idx&-idx;
		}
	};
	function<ll(int)> query = [&](int idx){
		ll sum = 0;
		while(idx){
			sum += bit[idx];
			idx -= idx&-idx;
		}
		return sum;
	};
	ll invs = 0;
	forr(i,N-1,0){
		invs += query(val[i]);
		update(val[i]+1,1);
	}
	//cout << invs << "\n";
	ll petr = 3*N;
	if((invs%2)^(N%2)) cout << "Um_nik\n";
	else cout << "Petr\n";
}
