//A. Chain Reaction codeforces

#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+100
typedef pair<int,int> ii;
vector<ii> segment;
int n,memo[MAX];

bool _s(ii a,ii b){
	return a.second < b.second;
}
int dp(int pos){
	if(pos < 0) return 0;
	if(memo[pos] != -1)return memo[pos];
	int ini = 0, fin = pos+1;
	while(ini < fin){
		int mit = (ini+fin)>>1;
		if(segment[mit].second < segment[pos].first) ini = mit+1;
		else fin = mit;
	}
	ini--;
	if(ini < 0 || segment[ini].second >= segment[pos].first) memo[pos] = 1;
	else memo[pos] = 1+dp(ini);
	return memo[pos];
}
int main(){
	memset(memo,-1,sizeof memo);
	cin >> n;
	forn(i,0,n){
		int a,b; cin >> a >> b;
		segment.push_back({a-b,a});
	}
	sort(segment.begin(),segment.end(),_s);
	int maxi = -1<<30;
	forn(i,0,n) maxi = max(maxi,dp(i));
	cout << n-maxi << "\n";
}
