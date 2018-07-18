#include <bits/stdc++.h>
using namespace std;

vector<int> numeroshumble;

int humble[5000];

int cribaHumble(int maxi){
	int numero[] = {2,3,5,7};
	humble[1] = 1;
	for(int i = 0; i < 4; i++){
		for(int j = numero[i]; j <= maxi; j += numero[i]){
			humble[j] = 1;
		}
	}
	numeroshumble.push_back(-1);
	for(int i = 1; i <= maxi; i++) if(humble[i] == 1) numeroshumble.push_back(i);

}

int n;

int main(){
	cribaHumble(5000);
	while(cin >> n,n){
		cout << numeroshumble[n] << "\n";
	}
}
