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
int main(){
	string T,P;
	cin >> T;
	cin >> P;
	pre(P);
	search(T,P);
}
