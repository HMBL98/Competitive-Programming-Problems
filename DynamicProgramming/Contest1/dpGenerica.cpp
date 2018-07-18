#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
//12315246345345

map < pair<ulli,ulli>,ulli > memo;

ulli dp(int pot,ulli total){
	ulli maximo =  (1ULL << (pot+2))-2;

	if(total == 0) return 1;
	if(pot < 0) return 0;
        if(pot < 63 && maximo < total)return 0;
	pair<ulli,ulli> target(pot,total);
	if(memo[target]) return memo[target];
	ulli notomar = 0,tomar1 = 0,tomar2 = 0;
	notomar += dp(pot-1,total);
        if(total >= (1ULL << pot) ) tomar1 += dp(pot-1,total-(1ULL<<pot));
        if(pot < 63 && total >= (1ULL<<(pot+1)) ) tomar2 += dp(pot-1,total-(1ULL<<(pot+1)));
	memo[target] = notomar+tomar1+tomar2;
	return memo[target];
}
int main(){
	ulli x;
	cin >> x;
	cout << dp(63,x) << endl;
}
