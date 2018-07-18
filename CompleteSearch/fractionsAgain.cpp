#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
	optimizar_io;
	int k;
	while(cin >> k){
		int x,y = k;
		int cuantos = 0;
		vector< pair<int,int> > respuestas;
		do{
			y++;
			x = (k*y)/(y-k);
			int izq = x*y;
			int der = k*(y+x);
			if(izq == der && x >= y){
				cuantos++;
				respuestas.push_back({x,y});
			}
		}while(x >= y);
		cout << cuantos << endl;
                for(int i = 0; i < respuestas.size(); i++){
                                cout << "1/" << k << " = ";
                                cout << "1/" << respuestas[i].first << " + ";
                                cout << "1/" << respuestas[i].second << endl;
                        }

	}
}
