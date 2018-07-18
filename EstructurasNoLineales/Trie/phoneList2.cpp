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

#define MN 100000+10 // number of nodes

struct node{
	int isWord;
	map<char,int> child;
};
struct trie{
	node tree[MN];
	int nodes;
	void init(){
		nodes = 0;
		tree[nodes].isWord = 0;
	}
	bool add(const string s){
		int cur = 0;
		bool status = true;
		for(auto &c : s){
			if(tree[cur].child.find(c) == tree[cur].child.end()){
				tree[cur].child[c] = ++nodes;
				tree[nodes].isWord = 0;
			}
			cur = tree[cur].child[c];
			if(tree[cur].isWord)status = false;
		}
		if(tree[cur].child.size()){
			status = false;
		}
		tree[cur].isWord++;
		return status;
	}
};
int t,n;
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
        while(t--){
		trie t1; t1.init();
                cin >> n;
                bool status = true;
                while(n--){
                        cin >> s;
                        if(!t1.add(s))status = false;
                }
                cout << ((status) ? "YES\n" : "NO\n");
        }
}
