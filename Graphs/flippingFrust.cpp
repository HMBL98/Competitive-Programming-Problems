#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
vector<int> visitado;
int c,n,l,r,t;


int main(){
	optimizar_io;
	cin >> c;
	while(c--){
		cin >> n >> l >> r >> t;
		visitado.assign(n+t,-1);
		queue<int> q;
		q.push(1);
		int res = -1;
		visitado[1] = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == t){
				res = visitado[u];
				break;
			}
			if(u+r <= n && visitado[u+r] == -1){
				visitado[u+r] = visitado[u]+1;
				q.push(u+r);
			}
			if(u-l > 0 && visitado[u-l] == -1){
				visitado[u-l] = visitado[u]+1;
				q.push(u-l);
			}
		}
		if(res != -1)cout << res << '\n';
		else cout << "uh-oh!\n";
	}
}
