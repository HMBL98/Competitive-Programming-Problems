#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int b[MAX];string P;

void pre(){
	int i = 0, j = -1; b[0] = -1;
	while(i < P.size()){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
int T,n,k;
string ant,act;

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		int res = n*k;
		for(int i = 0; i < k; i++){
			if(i){
				cin >> act;
				if(act.compare(ant) != 0){
					P.clear();
					P = act+ant;
					pre();
					//cout << b[P.size()] << "\n";
					res -= b[P.size()];
				}else{
					res -= ant.size();
				}
				ant = act;
			}else{
				cin >> ant;
			}
		}
		cout << res << "\n";
	}
}
