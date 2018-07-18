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
typedef vector<string> vs;
//In worst case the trie will have number of nodes equal to the sum of lengths of the strings from the input,
//let's call that s. In worst case, each node will have number of edges equal to the size of the alphabet, let's call that a. 
//So, it should be s × a.
#define MAX 10000000+10
int trie[MAX][30],finish[MAX],n,k,ini,nxt = 1;
vs out;

void add(string s){
	int node = 0;
	for(auto &c : s){
		if(trie[node][c-'a'] == 0){
			trie[node][c-'a'] = nxt++;
		}
		node = trie[node][c-'a'];
	}
	finish[node] = 1;
}
int find(string s){
	int idx = 0;
	for(auto &c : s){
		if(trie[idx][c-'a'] == 0)return 0;
		idx = trie[idx][c-'a'];
	}
	return idx;
}
void gene(int idx,string s){
	if(ini != idx && finish[idx]){
		out.pb(s);
	}
	forn(i,0,27){
		char c = i+'a';
		if(trie[idx][i] != 0) gene(trie[idx][i],s+c);
	}
}
int ncase;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; vs dic(n);
	forn(i,0,n)cin >> dic[i];
	sort(dic.begin(),dic.end());
	forn(i,0,n)add(dic[i]);
	cin >> k;
	while(k--){
		cout << "Case #" << ++ncase << ":\n";
		string str; cin >> str;
		ini = find(str);
		if(ini != 0)gene(ini,"");
		if(out.empty())cout << "No match.\n";
		else{
			for(auto &s : out)cout << str << s << "\n";
		}
		out.clear();
	}
}
