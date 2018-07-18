#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> lista;
int t,n;
string cadena;

vi dfs_enum;
char c;int a,b;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void dfs(int u){
	dfs_enum[u] = 1;
	for(int j = 0; j < (int)lista[u].size(); j++){
		ii v = lista[u][j];
		if(!dfs_enum[v.first])
			dfs(v.first);
	}
}

int main(){
	optimizar_io;
	cin >> t;
	int su,us;
	while(t--){
		cin >> n;
		su = us = 0;
		lista.assign(n+1,vii());
		cin.clear();cin.ignore();
		while(getline(cin,cadena)){
			if(cadena.empty())break;
			sscanf(cadena.c_str(),"%c %d %d\n",&c,&a,&b);
			if(c == 'c'){
				lista[a].push_back({b,0});
				lista[b].push_back({a,0});
			}else{
				dfs_enum.clear();
				dfs_enum.assign(n+1,0);
				dfs(a);
				if(dfs_enum[b]){
					su++;
				}else{
					us++;
				}
			}
		}
		cout << su <<  "," << us << endl;
		if(t > 0) cout << endl;
		lista.clear();
	}
}
