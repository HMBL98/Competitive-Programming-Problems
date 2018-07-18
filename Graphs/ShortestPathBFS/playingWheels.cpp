//10067 - Playing with Wheels
#include <bits/stdc++.h>
using namespace std;


map<string,int> visitado;
set<string> imposibles;
string sour,dest,tmp;
int t,numeros[4],n;

int main(){
	cin >> t;
	while(t--){
		cin >> numeros[0] >> numeros[1] >> numeros[2] >> numeros[3];
		sour = ""+to_string(numeros[0])+to_string(numeros[1])+to_string(numeros[2])+to_string(numeros[3]);
		cin >> numeros[0] >> numeros[1] >> numeros[2] >> numeros[3];
		dest = ""+to_string(numeros[0])+to_string(numeros[1])+to_string(numeros[2])+to_string(numeros[3]);
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> numeros[0] >> numeros[1] >> numeros[2] >> numeros[3];
			tmp = ""+to_string(numeros[0])+to_string(numeros[1])+to_string(numeros[2])+to_string(numeros[3]);
			imposibles.insert(tmp);
		}
		queue<string> q; q.push(sour);
		visitado[sour] = 0;
		while(!q.empty()){
			string u = q.front(); q.pop();
			string v;
			for(int i = 0; i < u.size(); i++){
				v = u;
				if(v[i] != '9') v[i] = u[i]+1;
				else v[i] = '0';
				if(visitado.find(v) == visitado.end() && imposibles.find(v) == imposibles.end()){
					q.push(v);
					visitado[v] = visitado[u]+1;
				}
				v = u;
				if(v[i] != '0') v[i] = u[i]-1;
				else v[i] = '9';
				if(visitado.find(v) == visitado.end() && imposibles.find(v) == imposibles.end()){
                                        q.push(v);
                                        visitado[v] = visitado[u]+1;
                                } 
			}
		}
		if(visitado.find(dest) == visitado.end()) cout << -1 << "\n";
		else cout << visitado[dest] << "\n";
		visitado.clear(); imposibles.clear();
	}
}
