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

struct node{
	int isWord;
	map<char,node*> child;
	node():isWord(0){}
};
struct trie{
	node* root;
	trie(){root = new node();}
	bool add(string &str){
		node* cur = root;
		bool status = true;
		for(auto &c : str){
			if(cur->child.find(c) == cur->child.end()){
				cur->child[c] = new node();
			}
			cur = cur->child[c];
			if(cur->isWord)status = false;
		}
		if(cur->child.size())status = false;
		cur->isWord = 1;
		return status;
	}
	bool find(string & str){
		node* cur = root;
		for(auto &c: str){
			if(cur->child.find(c) == cur->child.end())return false;
			cur = cur->child[c];
		}
		return cur->isWord;
	}
};
int t,n;
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
        while(t--){
                trie * t1 = new trie();
                cin >> n;
                bool status = true;
                while(n--){
                        cin >> s;
                        if(!t1->add(s))status = false;
                }
                cout << ((status) ? "YES\n" : "NO\n");
        }
}
