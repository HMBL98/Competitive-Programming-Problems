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

#define MAX 1000000+10
int b[MAX];
void pre(string P){
	int i = 0, j = -1; b[0] = -1;
	while(i < P.size()){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
bool search(string T,string P){
	int i = 0, j = 0;
	vi pos;
        while(i < T.size()){
                while(j >= 0 && T[i] != P[j]) j = b[j];
                i++; j++;
                if(j == P.size()){
			pos.pb(i-j);
                        j = b[j];
                }
        }
	if(pos.size() >= 3 && pos[0] == 0 && pos[1] > 0 && pos[1] < T.size()-P.size() && pos[pos.size()-1] == T.size()-P.size())return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string txt; cin >> txt;
	pre(txt);

	int s = b[txt.size()];
	while(true){
		if(s == 0)break;
		string tmp = txt.substr(0,s);
		if(search(txt,tmp)){
			cout << tmp << "\n";
			return 0;
		}
		s = b[s];
	}
	cout << "Just a legend\n";

}
