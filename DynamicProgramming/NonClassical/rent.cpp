//RENT - Rent your airplane and make money
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10000+10
typedef long long ll;
typedef pair<int,int> ii;
vector< pair<ii,int> > info;
ll memo[MAX];
int T,N;

bool _s(pair<ii,int> a,pair<ii,int> b){
	if(a.first.second == b.first.second) return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}
ll dp(int pos){
	if(memo[pos] != -1)return memo[pos];
	if(pos < 0)return 0;
	ll ini = 0, fin = pos;
	ll tomar = 0,notomar = 0;
	while(ini < fin){
		ll mit = (ini+fin) >> 1;
		if(info[mit].first.second <= info[pos].first.first) ini = mit+1;
		else fin = mit;
	}
	int tmp = ini-1;
	if(tmp >= 0 && info[tmp].first.second > info[pos].first.first) tmp = -1;
	tomar = info[pos].second+dp(tmp);
	notomar = dp(pos-1);
	memo[pos] = max(tomar,notomar);
	return memo[pos];
}

int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i <= N; i++) memo[i] = -1;
		for(int i = 0; i < N; i++){
			int l,r,c; cin >> l >> r >> c;
			info.push_back({{l,l+r},c});
		}
		sort(info.begin(),info.end(),_s);
		//for(int i = 0; i < info.size(); i++) cout << info[i].first.first << " " << info[i].first.second << "\n";
		cout << dp(N-1) << "\n";
		info.clear();
	}
}
