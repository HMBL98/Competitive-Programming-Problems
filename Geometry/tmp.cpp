#include <bits/stdc++.h>
using namespace std;

int main(){
	string valor;
	while(cin >> valor){
		if(valor[0] == '?'){
			cout << "No sabe" << endl;
		}else{
			int a = stoi(valor);
			cout << a << endl;
		}
	}
}
