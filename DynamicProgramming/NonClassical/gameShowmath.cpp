//10400 - Game Show Math
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
vector<int> numero(100+10);
vector<char> respuestas;

int memo[100+10][32000*2+10];

int n,m,f; bool status;

bool mover(int x){
	if(x < -32000 || x > 32000)return false;
	return true;
}
int dp(int pos,int total){
	if(memo[pos][total+32000] != -1) return memo[pos][total];
	if(pos >= m){
		if(total == f){
			status = true;
			return 1;
		}else return 0;
	}
	int res = 0;
	if(!status && mover(total+numero[pos])){
		res = max(res,dp(pos+1,total+numero[pos]));
		if(res) respuestas.push_back('+');
	}
	if(!status && mover(total-numero[pos])){
		res = max(res,dp(pos+1,total-numero[pos]));
		if(res)respuestas.push_back('-');
	}
	if(!status && mover(total*numero[pos])){
		res = max(res,dp(pos+1,total*numero[pos]));
		if(res)respuestas.push_back('*');
	}
	if(!status && total%numero[pos] == 0 && mover(total/numero[pos])){
		res = max(res,dp(pos+1,total/numero[pos]));
		if(res)respuestas.push_back('/');

	}
	memo[pos][total+32000] = res;
	return res;
}

int main(){
	optimizar_io;
	cin >> n;
	while(n--){
		for(int i = 0; i < 100+10; i++)for(int j = 0; j < 32000*2+10; j++) memo[i][j] = -1;
		cin >> m;
		for(int i = 0; i < m; i++) cin >> numero[i];
		cin >> f;
		status = false;
		if(dp(1,numero[0])){
			reverse(respuestas.begin(),respuestas.end());
			for(int i = 0; i < m; i++){
				if(i != m-1) cout << numero[i] << respuestas[i];
				else cout << numero[i];
			}
			cout << "=" << f << endl;
		}else cout << "NO EXPRESSION" << endl;
		respuestas.clear();
	}

}
