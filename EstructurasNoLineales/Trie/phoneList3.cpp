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
};
struct trie{
	node* root;
	trie(){root = new node();}
	void add(string &str){
		node* cur = root;
		for(auto &c : str){
			if(cur->child.find(c) == cur->child.end()){
				cur->child[c] = new node();
			}
			cur = cur->child[c];
		}
		cur->isWord = 1;
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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
}
