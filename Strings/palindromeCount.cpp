#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; string s;
	cin >> k >> s;
	forn(i,0,s.size()){
		string tmp = s.substr(i,s.size()-i);
		cout << tmp << "\n";
	}
}
