//Anagrams by Stack
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 1000+10

string str1,str2,line;
bool status;

void dfs(int pos1,int pos2,string res,string cadena){
	if(pos2 == str2.size()){
		status = true;
		return;
	}
	if(pos1+1 <= str1.size() && !status){
		dfs(pos1+1,pos2,res+"i",cadena+str1[pos1]);
	}
	if(pos2+1 <= str2.size() && pos2+1 <= pos1 && !status){
		char tmp = cadena[cadena.size()-1];
		if(tmp == str2[pos2]){
			dfs(pos1,pos2+1,res+"o",cadena.substr(0,cadena.size()-1));
		}
	}
}

int n;

int main(){
	optimizar_io;
	while(cin >> n,n){
		forn(i,1,n+1) str1 += i+'0';
		cin.clear(); cin.ignore();
		while(getline(cin,line)){
			if(line[0] == '0')break;
			forn(i,0,line.size())if(line[i] != ' ')str2+=line[i];
			status = false;
			dfs(0,0,"","");
			if(status) cout << "Yes\n";
			else cout << "No\n";
			str2.clear();
		}
		cout << "\n";
		str1.clear();
	}
}
