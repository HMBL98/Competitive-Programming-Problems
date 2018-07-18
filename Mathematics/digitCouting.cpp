//1225 - Digit Counting
#include <bits/stdc++.h>
using namespace std;

int t,n;
long long botes[10];

int main(){
	cin >> t;
	while(t--){
		for(int i = 0; i < 10; i++) botes[i] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int tmp = i;
			while(tmp){
				botes[tmp%10]++;
				tmp /= 10;
			}
		}
		for(int i = 0; i < 10; i++){
			if(i) cout << " ";
			cout << botes[i];
		}
		cout << "\n";
	}
}

