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

const int MAXL = 1 << 17,MAXN = 1 << 10;

int N; bool subst[MAXN];

int root, nodes;
struct node{
	bool seen;
	int matchFail;
	vi matches;
	int fail;
	map<char,int> next;
}trie[MAXL];

void insert(string s, int id){
	int x = root;
	for(auto &c : s){
		int & nxt = trie[x].next[c];
		if (!nxt) nxt = ++nodes;
		x = nxt;
	}
	trie[x].matches.pb(id);
}
int target(int x, char ch){
	while(x && !trie[x].next.count(ch))x = trie[x].fail;
	return x ? trie[x].next[ch] : root;
}
void bfs(){
	trie[root].fail = 0; // nil
	queue<int> q;
	for(q.push(root); !q.empty(); q.pop()){
		int u = q.front();
		for(map< char, int >::iterator it = trie[u].next.begin(); it != trie[u].next.end(); ++it){
			char ch = it->first;
			int v = it->second;
			int f = target(trie[u].fail, ch);
			trie[v].fail = f;
			trie[v].matchFail = trie[f].matches.empty() ? trie[f].matchFail : f;
			q.push(v);
		}
	}
}
void search(string text){
	int x = root;
	forn(i,0,text.size()){
		x = target(x, text[i]);
		for(int t = x; t /*&& !trie[t].seen*/; t = trie[t].matchFail){
			trie[t].seen = true;
			forn(j,0,trie[t].matches.size()){
				cout << i << " " << trie[t].matches[j] << "\n";
				subst[trie[t].matches[j]] = true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string text,str;
	root = ++nodes;
	cin >> text;
	cin >> N;
	forn(i,0,N){
		cin >> str;
		insert(str, i);
	}
	bfs();
	search(text);
	return 0;
}
