#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoff(int n,int k){
	int res = 1;
	if(k > n-k) k = n-k;
	for(int i = 0; i < k; i++){
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}
int main(){
	cout << binomialCoff(8,2) << "\n";
}
