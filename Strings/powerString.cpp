#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000+10
#define forn(i,a,b) for(int i = a; i < b; i++)
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
	string P;
	while(cin >> P){
		if(P[0] == '.')break;
		pre(P);
		int act = P.size();
		int mini = 1<<20;

		while(1){
			int d = P.size()-b[act];
			if(d && P.size()%d == 0){
				mini = d;
				break;
			}
			act = b[act];
		}
		cout << P.size()/mini << "\n";
	}
}
