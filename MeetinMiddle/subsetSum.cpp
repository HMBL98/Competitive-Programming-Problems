#include <bits/stdc++.h>
using namespace std;

#define MAX 50
typedef long long ll;

ll n,a,b,values[MAX],res;
vector<ll> X,Y;

void computeSubArray(bool left,int t,int idx){
	for(int i = 1; i < (1<<t); i++){
		ll sum = 0;
		for(int j = 0; j < t; j++)
			if(i&(1<<j)) sum += values[j+idx];
		if(left) X.push_back(sum);
		else Y.push_back(sum);
		if(a <= sum && sum <= b)res++;
	}
}
int main(){
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) cin >> values[i];
	computeSubArray(true,n/2,0);
	computeSubArray(false,n-n/2,n/2);
	sort(Y.begin(),Y.end());

	for(int i = 0; i < X.size(); i++){
		ll ini = 0, fin = Y.size();
		ll upper,lower,tmp;
		while(ini < fin){
			ll mitad = (ini+fin) >> 1;
			if(X[i]+Y[mitad] <= b)ini = mitad+1;
			else fin = mitad;
		}
		upper = ini;
		ini = 0; fin = Y.size();
		while(ini < fin){
			ll mitad = (ini+fin) >> 1;
			if(X[i]+Y[mitad] < a)ini = mitad+1;
			else fin = mitad;
		}
		lower = ini;
		res += upper-lower;
	}
	if(a <= 0 && 0 <= b)res++;
	cout << res << "\n";
}

