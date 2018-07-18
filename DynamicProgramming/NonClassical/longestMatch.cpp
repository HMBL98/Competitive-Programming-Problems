#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i=a;i<b;i++)

string s1,s2;
vector<string> v1,v2;
int memo[1000+10][1000+10];

int dp(int i,int j){
	if(i >= v1.size() || j >= v2.size()) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	int tomar = -1,notomar1 = -1,notomar2 = -1;
	if(v1[i].compare(v2[j]) == 0){
		tomar = 1+dp(i+1,j+1);
	}
	notomar1 = dp(i+1,j);
	notomar2 = dp(i,j+1);
	int res = max(tomar,notomar1);
	res = max(res,notomar2);
	memo[i][j] = res;
	return res;
}
int caso;
int main(){
	while(getline(cin,s1)){
		getline(cin,s2);
		memset(memo,-1,sizeof memo);

		cout.width(2); cout << right << ++caso << ". ";
		if(s1.empty() || s2.empty()){
			cout << "Blank!\n";
			continue;
		}
		forn(i,0,s1.size()){
			if(s1[i] < 48 || (s1[i] > 57 && s1[i] < 65) || (s1[i] > 90 && s1[i] < 97) || s1[i] > 122) s1[i] = ' ';
		}
		forn(i,0,s2.size()){
			if(s2[i] < 48 || (s2[i] > 57 && s2[i] < 65) || (s2[i] > 90 && s2[i] < 97) || s2[i] > 122) s2[i] = ' ';
                }
		stringstream ss1(s1);
                stringstream ss2(s2);
		string tmp;
		while(ss1 >> tmp) v1.push_back(tmp);
		while(ss2 >> tmp) v2.push_back(tmp);

		cout << "Length of longest match: " <<  dp(0,0) << "\n";

		v1.clear();
		v2.clear();
	}
}

