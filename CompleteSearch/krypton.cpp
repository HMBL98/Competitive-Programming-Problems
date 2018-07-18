#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int N,L;
bool can (string s){
    if (s.size() == 1) return true;
	for (int i=0; i < (int)(s.size()/2); i++){
		string s1 = s.substr(s.size()-i-1,i+1);
	    string s2 = s.substr(s.size()-(2*i)-2,i+1);
	    if(s2.size()==0) s2 = s.substr(0,1);
	    //cout << s << " " << i << " "<< s1 << " " << s2 << endl;
	    if (s1.compare(s2) == 0) return false;
	}
	return true;
}
bool status;
int no;
void generate (string cadena){
	if (no == N){
		//cout << cadena << endl;
		int a = 0;
		for(int i = 1; i <= cadena.size(); i++){
			cout << cadena[i-1];
			if(i%4 == 0 && i != cadena.size()){
				a++;
				if(a%16 == 0)cout << endl;
				else cout << " ";
			}
		}
		cout << endl;
		cout << cadena.size() << endl;
		status = true;
		return;
	}
	string tmp;
	for (int i=0; i<L && !status; i++){
		tmp = cadena;
		tmp += 'A'+i;
		if (can (tmp)){
			no++;
			generate (tmp);
		}
	}
}


int main(){
	optimizar_io;
	while (cin >> N >> L && N){
		string cadena = "";
		status = false; 
		no = 0;
		generate(cadena);
	}
 
}
