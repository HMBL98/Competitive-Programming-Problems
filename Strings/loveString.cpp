#include <bits/stdc++.h>
using namespace std;

int t,q;
string s1,s2;

int main(){
	cin >> t;
	while(t--){
		cin >> s1;
		cin >> q;
		while(q--){
			cin >> s2;
			bool status = true;
			for(int i = 0; i < s2.size(); i++)if(i >= s1.size() || s1[i] != s2[i]){status = false; break;}
			if(status) cout << "y\n";
			else cout << "n\n";
		}
	}
}

