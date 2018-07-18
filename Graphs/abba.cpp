#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
map<string,int> visitado;
string cadena;

int main(){
	optimizar_io;
	cin >> cadena;
	queue<string> q; q.push(cadena);
	visitado.insert({cadena,0});

	int res,x,y;
	while(!q.empty()){
		string u = q.front(); q.pop();
		int distancia = visitado[u];
		bool palindromo = true;
		for(int i = 0,j = u.size()-1; i < u.size()/2; i++,j--) if(u[i] != u[j]){palindromo = false;break;}
		if(palindromo){
			res = distancia;
			break;
		}else{
			string uno = u,dos = u;
			x = distancia; y = u.size()-1-distancia;
			while(u[x] == u[y]) x++,y--;
			for(int i = 0; i < cadena.size(); i++) if(uno[i] == u[x]) uno[i] = u[y];
			for(int i = 0; i < cadena.size(); i++) if(dos[i] == u[y]) dos[i] = u[x];
			//cout << u << "\t" << uno << "\t" << dos << "\t" << distancia+1 << '\n';
			if(visitado.find(uno) == visitado.end()){
				visitado.insert({uno,distancia+1});
				//cout << visitado[uno] << '\n';
				q.push(uno);
			}
			if(visitado.find(dos) == visitado.end()){
				visitado.insert({dos,distancia+1});
				//cout << visitado[dos] << '\n';
				q.push(dos);
			}
		}
	}
	cout << res << '\n';
}
