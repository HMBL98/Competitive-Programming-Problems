//10063 - Knuth's Permutation
#include <bits/stdc++.h>
using namespace std;
string s;

void backtrack(string res,int pos){
	if(res.size() >= s.size()){
		cout << res << "\n";
		return;
	}
	string tmp;
	for(int i = 0; i <= res.size(); i++){		
		tmp = "";
		if(i == 0){
			tmp += s[pos]+res;
		}else if(i == res.size()){
			tmp += res+s[pos];
		}else{
			tmp += res.substr(0,i)+s[pos]+res.substr(i,s.size()-i+1);
		}
		backtrack(tmp,pos+1);
	}
	
}
int caso;
int main(){
	while(cin >> s){
		if(caso++)cout << "\n";
		string tmp = "";
		tmp += s[0];
		backtrack(tmp,1);
	}
}


