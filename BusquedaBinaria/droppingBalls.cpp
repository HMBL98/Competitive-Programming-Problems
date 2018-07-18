#include <bits/stdc++.h>
using namespace std;

int t,d,l;

void recorrido(int pos){
	if((pos<<1) > ((1<<d)-1) || ((pos<<1)+1) > ((1<<d)-1)){
		cout << pos << endl;
		return;
	}
	int next;
	if(l%2 == 0){
		int pares = (l/2);
		if(pares%2 == 0){
			recorrido((pos<<1)+1);
		}else{
			recorrido(pos<<1);
		}
	}else{
		int impares = (l/2);
		if(impares%2 != 0){
			recorrido((pos<<1)+1);
		}else{
			recorrido(pos<<1);
		}
	}
}
int main(){
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> d >> l;
		int next;
		if(l%2 != 0){
			next = 2;
		}else{
			next = 3;
		}
		recorrido(next);
	}
}
