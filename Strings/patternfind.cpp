#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000000+9
int b[MAX],N,values[MAX];

void pre(){
	int i = 0, j = -1; b[0] = -1;
	while(i < N){
		while(j >= 0 && values[i] != values[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
int main(){
	optimizar_io;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> values[i];
	pre();
	int res = -1;
	for(int i = 0; i <= N; i++) res = max(res,b[i]);
	cout << res << "\n";
}
