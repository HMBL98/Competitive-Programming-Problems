//11475 - Extend to Palindrome
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string in,p,ori;
	while(cin >> in){
		p = in;
		ori = in;
		reverse(in.begin(),in.end());
		p = in + "$" + p,
		pre(p);
		string p1 = ori.substr(0,ori.size()-b[p.size()]);
		reverse(p1.begin(),p1.end());
		string res = ori+p1;
		cout << res << "\n";
	}
}
