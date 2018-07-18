//B. Delete from the Left codeforces
#include <bits/stdc++.h>
using namespace std;

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
void search(string T,string P){
	int i = 0, j = 0;
	while(i < T.size()){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if(j == P.size()){
			cout << P << " found at index " << i-j << "\n";
			j = b[j];
		}
	}
}
string s1,s2;
int main(){
	cin >> s1 >> s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	string pat = s1+'$'+s2;
	cout << pat << "\n";
	pre(pat);
	int res = -1;
	for(int i = s1.size()+1; i <= pat.size(); i++){
		cout << b[i] << " ";
		res = max(res,b[i]);
	}
	cout << "\n";
	cout << s1.size()+s2.size()-2*res << "\n";
}
