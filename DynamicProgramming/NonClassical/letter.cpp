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

string str;
const int inf = 1<<29;
int memo[MAX][2];

bool mayu(char c){
	int tmp = c-'A';
	if(0 <= tmp && tmp <= 'Z'-'A')return true;
	return false;
}
int dp(int pos,int mini){
	if(pos == str.size())return 0;
	int &res = memo[pos][mini];
	if(res != -1)return res;
	res = inf;
	if(mini){
		if(mayu(str[pos])){
			res = min(res,1+dp(pos+1,mini));
		}else{
			res = min(res,dp(pos+1,mini));
		}
	}else{
		if(mayu(str[pos])){
			res = min(res,dp(pos+1,mini));
		}else{
			res = min(res,dp(pos+1,1));
			res = min(res,1+dp(pos+1,mini));
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,MAX)forn(j,0,2)memo[i][j] = -1;
	cin >> str;
	cout << dp(0,0) << "\n";
}
