#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector< pair<ii,int> > datos;
ll dp[20][20];

bool s(pair<ii,int> a,pair<ii,int> b){
	ll _a = a.first.first*a.first.second;
	ll _b = b.first.first*b.first.second;
	if(_a == _b) return a.second < b.second;
	return _a > _b;
}
int C(int x,int y){
	x--;y--;
	int max1 = -1,max2 = -1;
	ll area,res = 0;
	for(int i = x; i <= y; i++){max1 = max(max1,datos[i].first.first); max2 = max(max2,datos[i].first.second);}
	area = max1*max2;
	for(int i = x; i <= y; i++)res += (area-(datos[i].first.first*datos[i].first.second))*datos[i].second;
	return res;
}
int n,k;

int main(){
	while(cin >> n >> k){
		for(int i = 0; i < n; i++){
			int x,y,c; cin >> x >> y >> c;
			datos.push_back({{x,y},c});
		}
		sort(datos.begin(),datos.end(),s);
		//for(int i = 0; i < n; i++) cout << datos[i].first.first << " " << datos[i].first.second << " " << datos[i].second << " \n";
		for(int i = 1; i <= k; i++) for(int j = 1; j <= n; j++) dp[i][j] = 1<<20;
		for(int i = 1; i <= n; i++) dp[1][i] = C(1,i);
		for(int i = 2; i <= k; i++){
			for(int j = i; j <= n; j++){
				for(int l = 1; l < j; l++){
					dp[i][j] = min(dp[i][j],dp[i-1][l]+C(l+1,j));
					//cout << i << " " << j << " " <<  l << " " << j-1 << " " << C(l+1,j) << "\n";
				}
			}
		}
		//for(int i = 1; i <= k; i++)for(int j = 1; j <= n; j++)cout << i << " " << j << " " << dp[i][j] << "\n";
		cout << dp[k][n] << "\n";
		datos.clear();
	}
}
