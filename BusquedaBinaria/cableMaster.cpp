#include <bits/stdc++.h>
using namespace std;

vector<double> cables;

int cuantos(double n){
 	int res = 0;
	for(int i = 0; i < cables.size(); i++){
		int c = (int)((cables[i])/n);
		res += c;
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	for(int asd = 1; asd <= t; asd++){
		int n,k;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			double tmp;
			cin >> tmp;
			cables.push_back(tmp);
		}
		double ini = 0.00,fin = 1000000.00;
		double mitad;
		for(int i = 0; i < 100; i++){
			mitad = (double)((ini+fin)/2);
			int c = cuantos(mitad);
			//cout << "con " << mitad << " = " << c << endl;
			if(c < k){
				fin = mitad;
			}else{
				ini  = mitad;
			}
		}
		if(mitad >= 0.01){
			auto std = std::to_string(mitad);
			int pos = std.find('.');
			cout << std.substr(0,pos+1) << std.substr(pos+1,2) << endl; 
		}else{
			printf("0.00\n");
		}
		if(asd != t) cout << endl;
		cables.clear();
	}
}
