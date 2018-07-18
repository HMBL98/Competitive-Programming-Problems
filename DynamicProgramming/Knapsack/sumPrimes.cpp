#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int n,k;
int _criba;
bitset<1120+10> bs; 
vi primos;

ll memo[1120+10][1120+10][20];
void criba(int mayor){
	_criba = mayor+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i <= _criba; i++){
		if(bs[i]){
			for(int j = i*i; j <= _criba; j += i) bs[j] = 0;
			primos.push_back((int)i);
		}
	}
}
ll dp(int pos,int total,int cuantos){
	if(memo[pos][total][cuantos] != -1) return memo[pos][total][cuantos];
	if(cuantos == 0){
		if(total == 0) return 1;
		return 0;
	}
	ll res = 0;
	for(int i = pos; primos[i] <= total; i++){
		res += dp(i+1,total-primos[i],cuantos-1);
	}
	memo[pos][total][cuantos] = res;
	return res;
}
ll dp2(int pos,int total,int cuantos){
        if(memo[pos][total][cuantos] != -1) return memo[pos][total][cuantos];
        if(cuantos == 0){
                if(total == 0) return 1;
                return 0;
        }
	int res = 0;
        if(primos[pos] <= total) res += dp(pos+1,total-primos[pos],cuantos-1);
	res += dp(pos+1,total,cuantos);
        memo[pos][total][cuantos] = res;
        return res;
}
int main(){
	criba(1120+10);
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&n,&k),(n||k)){
		int maneras = dp2(0,n,k);
		printf("%ld\n",maneras);
	}
}
