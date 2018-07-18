//10980 - Lowest Price in Town
#include <bits/stdc++.h>
using namespace std;

double memo[30][1000+100];

vector< pair<int,double> > valores;
int m,target;
double price;


double dp(int pos,int cuantos){
	if(memo[pos][cuantos] != -1) return memo[pos][cuantos];
	if(cuantos >= target) return 0;
	if(pos >= valores.size()) return 1<<20;
	double tomar = valores[pos].second+dp(pos,cuantos+valores[pos].first);
	double notomar = dp(pos+1,cuantos);

	memo[pos][cuantos] = min(tomar,notomar);

	return memo[pos][cuantos];
}

int main(){
	int caso = 0;
	while(cin >> price >> m){
		valores.push_back({1,price});
		while(m--){
			int cuantos; double precio;
			cin >> cuantos >> precio;
			valores.push_back({cuantos,precio});
		}
		cout << "Case " << ++caso << ":\n";
		cin.clear(); cin.ignore();
		string linea; getline(cin,linea);
		stringstream ss(linea);
		while(ss >> target){
			for(int i = 0; i < 30; i++)for(int j = 0; j < 1000+100; j++) memo[i][j] = -1;
			double res = dp(0,0);
			string r = to_string(res);
			int pos = r.find('.');
			string r2 = r.substr(0,pos+3);
			cout << "Buy " << target << " for $" << r2 << endl;

		}
		valores.clear();
	}
}
