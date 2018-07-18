//12467 - Secret Word
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000+10
int b[MAX];

void pre(string P){
	int i = 0, j = -1; b[0] = -1;
	while(i < P.size()){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
int T;
int main(){
	cin >> T;
	while(T--){
		string in,P;
		cin >> in;
		P = in;
		reverse(in.begin(),in.end());
		P += '$'+in;
		pre(P);
		int maxi = -1;
		for(int i = in.size()+1; i <= P.size();i++) maxi = max(b[i],maxi);
		string res = P.substr(0,maxi);
		reverse(res.begin(),res.end());
		cout << res << "\n";
	}
}
