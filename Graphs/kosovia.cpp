#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main(){
	cin >> n;
	ll res = n-1;
	for(int i = 1; i <= n; i++){
		if(i+3 <= n){
			res++;
			res +=  (n-(i+3))/2;
		}
	}
	cout << res << '\n';

}
