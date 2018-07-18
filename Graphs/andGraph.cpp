#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MN 1000000+10

int trie[MN][2],finish[MN],nxt = 1;
unordered_map<int,int> mapper;
void add(int n){
	int node = 0;
	forr(i,22,0){
		char c = (n&(1<<i)) ? '1' : '0';
		//cout << c;
		if(trie[node][c-'0'] == 0) trie[node][c-'0'] = nxt++;
		node = trie[node][c-'0'];
	}
	//cout << "\n";
	finish[node] = 1;
}
const int MAX = (1<<22)+10;
int n,m,val[MAX],p[MAX],setSize[MAX],_rank[MAX],numSets;

void init(int s){
	numSets = s;
	forn(i,0,s){
		p[i] = i;
		setSize[i] = 1;
		_rank[i] = 0;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
void unionSet(int x,int y){
	numSets--;
	if(_rank[x] > _rank[y]){
		p[y] = x; setSize[x] += setSize[y];
	}else{
		p[x] = y; setSize[y] += setSize[x];
		if(_rank[x] == _rank[y])_rank[y]++;
	}
}
void find(int x,int y,int pos,int node){
	if(pos < 0){
		cout << x << " " << y << "\n";
		int i = findSet(mapper[x]),j = findSet(mapper[y]);
		if(i != j){
			//cout << x << " " << y << "\n";
			unionSet(i,j);
		}
	}
	if(x&(1<<pos)){
		if(trie[node][0] == 0)return;
		else find(x,y,pos-1,trie[node][0]);
	}else{
		if(trie[node][1] != 0){
			find(x,y|(1<<pos),pos-1,trie[node][1]);
		}
		if(trie[node][0] != 0){
			find(x,y,pos-1,trie[node][0]);
		}
	}
}

int counter = 0;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	init(m);
	forn(i,0,m){
		cin >> val[i];
		add(val[i]);
		mapper[val[i]] = counter++;
	}
	forn(i,0,m)find(val[i],0,22,0);
	cout << numSets << "\n";
}
