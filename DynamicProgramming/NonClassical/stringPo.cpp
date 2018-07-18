#include <bits/stdc++.h>
using namespace std;
int n;
set<string> vistas;
bool status;
int grupos(string cadena){
	int res = 1;
	for(int i = 1; i < cadena.size(); i++){
		if(cadena[i] != cadena[i-1])res++;
	}
	return res;
}
string remover(string cadena,int pos){
	//cout << cadena << " " << pos << endl;
	int cual = 1;
	int a,b;
	for(int i = 0; i < cadena.size(); i++){
		int j = i+1;
		for(; j < cadena.size() && cadena[j] == cadena[i]; j++);
		if(cual == pos){
			a = i; b = j-1;
			break;
		}
		i = j-1;
		cual++;
	}
	//cout << a << " " << b << endl;
	string res = "" +cadena.substr(0,a) + cadena.substr(b+1,cadena.size());
	if(b-a+1 == 1) return cadena;
	else return res;
}
void backtrack(string cadena){
	if(cadena.size() == 0){
		status = true;
		return;
	}
	if(vistas.find(cadena) != vistas.end())return;
	if(!status){
		//cout << cadena << endl;
		vistas.insert(cadena);
		int maneras = grupos(cadena);
		for(int i = 1; i <= maneras; i++){
			backtrack(remover(cadena,i));
		}
	}
}
int main(){
	cin >> n;
	while(n--){
		vistas.clear();
		status = false;
		string cadena;
		cin >> cadena;
		backtrack(cadena);
		if(status) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
