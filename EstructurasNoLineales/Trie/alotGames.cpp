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

//In worst case the trie will have number of nodes equal to the sum of lengths of the strings from the input,
//let's call that s. In worst case, each node will have number of edges equal to the size of the alphabet, let's call that a. 
//So, it should be s × a.
#define MN 1000000+10 //number of nodes
#define MA 26 //size of alphabet
int trie[MN][26],finish[MA],nxt = 1;
int n,k;

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

int backtrack(int node,int turn){
	int winner = 0;
	bool found = false;
	forn(i,0,26){
		if(trie[node][i] != 0){
			winner = max(winner,backtrack(trie[node][i],!turn));
			found = true;
		}
	}
	if(!found) return !turn;
	return winner;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	while(n--){
		string s; cin >> s;
		add(s);
	}
	int winner = backtrack(0,1);
	if(winner){
		if(k%2 == 0)cout << "Second\n";
		else cout << "First\n";
	}else{
		cout << "Second\n";
	}
}

