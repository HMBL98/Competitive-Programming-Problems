#include <bits/stdc++.h>
using namespace std;

int T,N;

struct info{
	int uno,dos;
};
vector<info> personas;
bool function(info a,info b){
	int a1 = a.uno*a.dos;
	int b1 = b.uno*b.dos;
	return a1 > b1;
}
int main(){
	cin >> T;
	while(T--){
		cin >> N;
		int total = 0;
		for(int i = 0; i < N; i++){
			info tmp;
			cin >> tmp.uno >> tmp.dos;
			total += tmp.uno;
			personas.push_back(tmp);
		}
		sort(personas.begin(),personas.end(),function);
		int parcial = personas[0].uno + personas[0].dos;
		int pasado = personas[0].uno;
		for(int i = 1; i < personas.size(); i++){
			pasado += personas[i].uno + personas[i].dos;
		 	if(total < pasado) total = pasado;
			pasado = personas[i].uno;
		}
		cout << total << endl;
		personas.clear();
	}
}
