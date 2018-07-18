#include <bits/stdc++.h>
using namespace std;
string source;
int t;
long long mayor;
void backtrack(int pos,int suma,string res){
	if(pos > source.size()-1){
		//cout << res << " " << suma <<  endl;
		/*if(suma%3 == 0){
			sort(res.begin(),res.end());
			reverse(res.begin(),res.end());
			if(res[res.size()-1] == '0' || res[res.size()-1] == '5'){
				long long numero = stoi(res);
				mayor = (numero > mayor) ? numero : mayor;
			}
		}*/
		return;
	}
	string resT = res;
	if(source[pos] == '0'){
		res += '0';
		backtrack(pos+1,suma,res);
	}else{
		resT += source[pos];
		backtrack(pos+1,suma+source[pos]-'0',resT); //Agarramos
		backtrack(pos+1,suma,res); //No agarramos
	}
}
int main(){
	cin >> t;
	while(t--){
		cin >> source;
		mayor = -1;
		string a = "";
		backtrack(0,0,a);
		cout << "Fin" << endl;
	}
}
