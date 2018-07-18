//1029. Ministry
#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,n) for (int i=a;i<n;i++)
typedef long long ll;
ll n,m,cost[110][510],memo[110][510];

ll dp(int i,int j,int pi,int pj){
	if(i < 0 || j < 0 || j >= m)return 1LL<<50;
	if(i == 0) return cost[i][j];
	//if(memo[i][j] != -1)return memo[i][j];
	ll uno = 1LL<<60,dos = 1LL<<60,tres = 1LL<<60;
	if(pi != i-1 && pj != j )uno = dp(i-1,j,i,j);
	if(pi != i && pj != j+1 )dos = dp(i,j+1,i,j);
	if(pi != i && pj != j-1 )tres = dp(i,j-1,i,j);
	ll mini = (uno < dos) ? uno : dos;
	mini = (mini < tres) ? mini : tres;
	ll tomar = cost[i][j] + mini;
	//memo[i][j] = tomar;
	cout << i << " " << j << " " << tomar << "\n";
	return tomar;
}
vector<int> res;
/*void printP(int i,int j){
	res.push_back(j);
	if(i == 0)return;
	if(cost[i][j] + dp(i-1,j) == dp(i,j)){
		printP(i-1,j);
		return;
	}else if(cost[i][j]+dp(i,j+1) == dp(i,j)){
		printP(i,j+1);
		return;
	}
}*/
int main(){
	//memset(memo,-1,sizeof memo);
	cin >> n >> m;
	forr(i,0,n)forr(j,0,m)cin >> cost[i][j];
	ll mini = 1LL<<60;
	int id1,id2;
	forr(i,0,m){
		if(dp(n-1,i,-1,-1) < mini){
			mini = dp(n-1,i,n-1,i);
			id1 = n-1;
			id2 = i;
		}
	}
	cout << mini << "\n";
	//printP(id1,id2);
	reverse(res.begin(),res.end());
	forr(i,0,res.size()){
		if(i) cout << " ";
		cout << res[i]+1;
	}
	cout << "\n";
}

