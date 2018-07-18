#include <bits/stdc++.h>
using namespace std;

int s,d;
int main(){
	while(cin >> s >> d){
		long long a,b,res = -1000000000;
		long long ares,bres;
		for(int i = 0; i <= 5; i++){
			a = i;
			b = 5-a;
			if((s*a-b*d) < 0 && s*a < b*d && (s*a-b*d) > res){
				ares = a; bres = b;
				res = s*a-b*d;
			}
		}
		long long ans;
		switch(bres){
			case 1:
				ans = 10*s-2*d;
			break;
			case 2:
				ans = 8*s-4*d;
			break;
			case 3:
				ans = 6*s-6*d;
			break;
			case 4:
				ans = 3*s-9*d;
			break;
			case 5:
				ans = -1;
			break;
		}
		if(ans > 0){
			cout << ans << endl;
		}else{
			cout << "Deficit" << endl;
		}
	}
}
