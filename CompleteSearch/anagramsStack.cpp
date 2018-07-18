//Anagrams by Stack
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,b) for(int i = a; i < b; i++)
string str1,str2;

stack<char> pila;

void dfs(int pos1,int pos2,string res,string cadena){
	if(pos2 == str2.size()){
		forn(i,0,res.size()){
			if(i) cout << " ";
			cout << res[i];
		}
		cout << "\n";
		return;
	}
	if(pos1+1 <= str1.size()){
		dfs(pos1+1,pos2,res+"i",cadena+str1[pos1]);
	}
	if(pos2+1 <= str2.size() && pos2+1 <= pos1){
		char tmp = cadena[cadena.size()-1];
		if(tmp == str2[pos2]){
			dfs(pos1,pos2+1,res+"o",cadena.substr(0,cadena.size()-1));
		}
	}
}

int main(){
	optimizar_io;
	while(cin >> str1 >> str2){
		cout << "[\n";
		dfs(0,0,"","");
		cout << "]\n";
	}
}
