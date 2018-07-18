#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
string toString (ll number){
	stringstream ss;
	ss << number;
	return ss.str();
}
string convertir(ll n,ll b){
	string res = "";
	do{
		ll tmp = n%b;
		if(tmp >= 10) res += 'A'+(tmp-10);
		else res += toString(n%b);
	}while(n=n/b);
	reverse(res.begin(),res.end());
	return res;
}
bool esPalindromo(string tmp){
	//if(tmp[0] == '0' || tmp[tmp.size()-1] == '0') return false;
	for(int i = 0, j = tmp.size()-1;  i < tmp.size()/2; i++,j--){
		if(tmp[i] != tmp[j]) return false;
	}
	return true;
}
int main(){
	optimizar_io;
	ll n;
	ll s;
	while(cin >> n >> s){
	        ll c = 0;
		while(c != n){
			s++;
			ll co = 0;
			for(int i = 2; i <= 10; i++){
				if(esPalindromo(convertir(s,i))){
					//cout << "en base " << i << endl;
					co++;
				}
			}
			if(co >= 2){
		 		cout << s << endl;
				c++;
			}
		}
		
	}
	return 0;
}
