#include <bits/stdc++.h>
using namespace std;


int t;string s;

int main(){
	cin >> t;
	while(t--){
		cin >> s;
		
		long long res = 1;
		bool palindromo = true;
		for(int i = 0,j = s.size()-1; i < s.size()/2; i++,j--){
			if(s[i] != '?' && s[j] != '?' && s[i] != s[j]){palindromo = false; break;}
			if(s[i] == '?' && s[j] == '?') res = (res*26)%10000009;
		}
		if(s.size()%2 != 0 && s[s.size()/2] == '?') res = (res*26)%10000009;
		if(palindromo) 	cout << res << "\n";
		else cout << 0 << "\n";
	}
}
