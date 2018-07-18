#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100+10
typedef long long ll;
typedef pair<ll,ll> ii;

ii coor[MAX];
string s;
ll a,b;

int main(){
	cin >> a >> b >> s;
	if(!a && !b){
		cout << "Yes\n";
		return 0;
	}
	ll x = 0, y = 0;
	forn(i,1,s.size()+1){
		switch(s[i-1]){
			case 'U':
				y++;
			break;
			case 'D':
				y--;
			break;
			case 'L':
				x--;
			break;
			case 'R':
				x++;
			break;
		}
		cout << x << " " << y << "\n";
		coor[i].first = x;
		coor[i].second = y;
	}
	if(!coor[s.size()].first && !coor[s.size()].second){
		forn(i,0,s.size()){
                        if(coor[i].first == a && coor[i].second == b){
				cout << "Yes\n";
				return 0;
			}
                }
		cout << "No\n";
		return 0;
	}
	function<int(ll)> ev = [&](ll v){
		int n = s.size();
		forn(i,0,n+1){
			if(coor[i].first+coor[n].first*v == a && coor[i].second+coor[n].second*v == b) return 0;
		}
		if(coor[n].first == 0){
			if(b < 0 || coor[n].second < 0) return (coor[n].second+coor[n].second*v < b) ? 1 : -1;
			else return (coor[n].second+coor[n].second*v < b) ? -1 : 1;
		}else if(coor[n].second == 0){
			if(a < 0 || coor[n].first < 0) return (coor[n].first+coor[n].first*v < a) ? 1 : -1;
                        else return (coor[n].first+coor[n].first*v < a) ? -1 : 1;
		}else{
			if(coor[n].first+coor[n].first*v == a){
				if(b < 0 || coor[n].second < 0) return (coor[n].second+coor[n].second*v < b) ? 1 : -1;
	                        else return (coor[n].second+coor[n].second*v < b) ? -1 : 1;
			}else{
				if(a < 0 || coor[n].first < 0) return (coor[n].first+coor[n].first*v < a) ? 1 : -1;
                                else return (coor[n].first+coor[n].first*v < a) ? -1 : 1;
			}
		}
	};
	ll ini = 1,fin = 4;
	while(ini <= fin){
		ll mit = (ini+fin) >> 1;
		ll val = ev(mit);
		cout << ini << " " << fin << " " << mit << " " << val << "\n";
		if(val == 0){
			cout << "Yes\n";
			return 0;
		}else if(val == -1){
			ini = mit+1;
		}else{
			fin = mit-1;
		}
	}
	cout << "No\n";
}
