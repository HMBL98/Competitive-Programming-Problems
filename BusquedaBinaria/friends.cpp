#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c1,c2,x,y;

int main(){
	cin >> c1 >> c2 >> x >> y;
	ll ini = 0, fin = 1<<30LL;
	while(ini < fin){
		ll mitad = (ini+fin)>>1;
		ll cuantos = (mitad/x) + (mitad/y) - (mitad/(x*y));
		if(mitad < )
	}
}
