#include <bits/stdc++.h>
using namespace std;
#define MAX_L 8000+10
#define MAX_G 800+10
#define infinity 1111111111111111111ll
typedef long long ll;
ll L,G,lunatics[MAX_L],dp[MAX_G][MAX_L];
ll cost(int i, int j) {
    return i > j ? 0 : (lunatics[j] - lunatics[i-1]) * (j - i + 1);
}
void computeDP(ll k,ll ileft,ll iright,ll jleft,ll jright){
	if(ileft > iright) return;
	ll imid = ileft+iright >> 1;
	ll bestj = -1;
	dp[k][imid] = infinity;
	for(ll j = jleft; j <= jright; j++){
		if(dp[k-1][j]+cost(j+1,imid) < dp[k][imid]){
			dp[k][imid] = dp[k-1][j] + cost(j+1,imid);
			bestj = j;
		}
	}
	computeDP(k,ileft,imid-1,jleft,bestj);
	computeDP(k,imid+1,iright,bestj,jright);
}
int main(){
	scanf("%lld %lld",&L,&G);
	for(int i = 1; i <= L; i++){
		scanf("%lld",&lunatics[i]);
		lunatics[i] += lunatics[i-1];
	}
	for(int i = 0; i <= L; i++) dp[1][i] = lunatics[i]*i;
	for(int k = 2; k <= G; k++) computeDP(k,0,L,0,L);
	//for(int k = 0; k <= G; k++) for(int i = 0; i <= L; i++)  printf("%d %d =  %d \n",k,i,dp[k][i]);
	printf("%lld\n",dp[G][L]);
}

