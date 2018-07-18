//11875 - Brick Game
#include <bits/stdc++.h>
using namespace std;

int t,n,caso;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		int tmp,res;
		for(int i = 1; i <= n; i++){
			cin >> tmp;
			if(i == (n/2)+1) res = tmp;
		}
		cout << "Case " << ++caso << ": " << res << "\n";
	}
}

