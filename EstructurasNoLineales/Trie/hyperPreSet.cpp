#include <bits/stdc++.h>
using namespace std;

#define MAX 20000000
int trie[MAX][2],finish[MAX],nxt = 1;
int maxi = -1;
const int inf = 1<<20;
void add(string s){
	int node = 0;
	int res = 0;
	for(auto &c: s){
		if(trie[node][c-'0'] == 0){
			trie[node][c-'0'] = nxt++;
			maxi = max(maxi,res);
			res = -inf;
		}
		node = trie[node][c-'0'];
		res++;
	}
	finish[node] = 1;
}
int T,n;
string s;
int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		while(n--){
			cin >> s;
			add(s);
		}
		cout << maxi << "\n";
	}
}
