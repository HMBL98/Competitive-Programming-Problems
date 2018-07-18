#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int n,t;
int tracks[20+20];
int menor;
vector<int> res;

void backtrack(int j,int suma,vector<int> tmp){
	if(j == t || suma == n){
		if(n-suma < menor){
			res = tmp;
			menor = n-suma;
		}
		return;
	}
	vector<int> tm;
	int su;
	for(int i = j; i < t; i++){
		tm = tmp;
		su = suma;
		if(suma+tracks[i] <= n){
			tm.push_back(tracks[i]);
			su += tracks[i];
		}
		backtrack(i+1,su,tm);
	}
}
int main(){
	optimizar_io;
	while(cin >> n){
		cin >> t;
		for(int i = 0; i < t; i++)cin >> tracks[i];
		menor = 10000000;
		vector<int> tmp;
		backtrack(0,0,tmp);
		int suma = 0;
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << " ";
			suma += res[i];
		}
		cout << "sum:" << suma << endl;
		res.clear();
	}
}
