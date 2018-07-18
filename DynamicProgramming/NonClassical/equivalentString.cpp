//B. Equivalent Strings
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<string,string> ss;
map<ss,int> mapper;

int equivalent(string a,string b){
	ss act(a,b);
	if(mapper[act]) return mapper[act];
	if(a.compare(b) == 0) return 1;
	if(a.size()%2 != 0) return 2;
	string a1 = a.substr(0,a.size()/2);
	string a2 = a.substr(a.size()/2,a.size()-a.size()/2);
	string b1 = b.substr(0,b.size()/2);
	string b2 = b.substr(b.size()/2,b.size()-b.size()/2);
	if(equivalent(a1,b1) == 1 && equivalent(a2,b2) == 1){
		mapper[act] = 1;
		return 1;
	}
	if(equivalent(a1,b2) == 1 && equivalent(a2,b1) == 1){	
		mapper[act] = 1;
		return 1;
	}
	mapper[act] = 2;
	return 2;

}

int main(){
	optimizar_io;
	string a,b;
	cin >> a >> b;
	if(equivalent(a,b) == 1) cout << "YES\n";
	else cout << "NO\n";
}

