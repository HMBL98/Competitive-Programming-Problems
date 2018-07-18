#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

vector<int> valores;
int memo[21][110][110];
int t,tmp;
string linea;

int dp(int pos,int t1,int t2){
	if(pos >= valores.size())return (t1 == t2) ? 1 : 0;
	if(memo[pos][t1][t2] != -1)return memo[pos][t1][t2];
	int tomar = dp(pos+1,t1+valores[pos],t2);
	int tomar2 = dp(pos+1,t1,t2+valores[pos]);
	memo[pos][t1][t2] = max(tomar,tomar2);
	return memo[pos][t1][t2];
}

int main(){
	optimizar_io;
	cin >> t;
	cin.clear(); cin.ignore();
	while(t--){
		for(int i = 0; i < 21; i++)for(int j = 0; j < 110; j++)for(int k = 0; k < 110; k++)memo[i][j][k] = -1;
		getline(cin,linea);
		stringstream ss(linea);
		while(ss >> tmp)valores.push_back(tmp);
		int res = dp(0,0,0);
		if(res) cout << "YES\n";
		else cout << "NO\n";
		valores.clear();
	}

}
