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

#define MAX 100000+10
int trie[MAX][15],finish[MAX],nxt = 1;

bool add(string s){
        int node = 0;
	bool status = true;
        for(auto &c : s){
                if(trie[node][c-'0'] == 0){
                        trie[node][c-'0'] = nxt++;
                }
                node = trie[node][c-'0'];
		if(finish[node])status = false;
        }
	forn(i,0,10)
		if(trie[node][i] != 0){
			status = false;
			break;
		}
        finish[node] = 1;
	return status;
}

int t,n;
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		bool status = true;
		while(n--){
			cin >> s;
			if(!add(s))status = false;
		}
		cout << ((status) ? "YES\n" : "NO\n");
		forn(i,0,nxt){
			finish[i] = 0;
			forn(j,0,15)trie[i][j] = 0;
		}
		nxt = 1;
	}
}
