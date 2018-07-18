#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define max_n 50+10
typedef vector<int> vi;
typedef long long ll;

vector<vi> grafo;
vi visitado;

int n,gradoImpar;
char c;
bool posible;
ll fac[max_n];

ll multiplica(ll a,ll b){
	ll res = 0;
	while(b){
		if(b&1) res = (a+res)%mod;
		b >>= 1;
		a = ((a%mod)+(a%mod))%mod;
	}
	return res;
}
ll expo(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (a*res)%mod;
		b >>= 1;
		a = ((a%mod)*(a%mod))%mod;
	}
	return res;
}
ll factorial(ll n){
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= n; i++){
		fac[i] = multiplica(i,fac[i-1]);
	}
}
int dfs(int u,int p){
	visitado[u] = 1;
	int res = 1;
	if(grafo[u].size()&1) gradoImpar++;
	for(int i = 0; i < grafo[u].size(); i++){
		if(visitado[grafo[u][i]] == -1)res += dfs(grafo[u][i],u);
		if(p != grafo[u][i] && visitado[u] == visitado[grafo[u][i]]) posible = false;
	}
	visitado[u] = 2;
	return res;
}
int main(){
	factorial(50);
	cin >> n;
	grafo.assign(n,vi());
	visitado.assign(n,-1);
	for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
		cin >> c;
		if(c == 'Y'){
			grafo[i].push_back(j);
		}
	}
	int caminosH = 0;
	int componentes = 0;
	posible = true;
	for(int i = 0; i < n; i++){
		if(visitado[i] == -1){
			componentes++;
			gradoImpar = 0;
			int size = dfs(i,-1);
			if(gradoImpar > 2 || (size != 1 && gradoImpar == 0))posible = false;
			else if(size > 1) caminosH++;
		}
	}
	if(posible){
		ll res = multiplica(fac[componentes],expo(2,caminosH));
		cout << res << "\n";
	}else cout << 0 << "\n";
}
