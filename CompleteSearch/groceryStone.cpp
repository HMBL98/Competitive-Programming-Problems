/*
	Importante
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int c = 1;
	for(double a = 0.10; a <= 20.00; a += 0.01){
		for(double b = 0.10; b <= 20.00; b += 0.01){
			for(double c = 0.10; c <= 20.00; c += 0.01){
				for(double d = 0.10; d <= 20.00; d += 0.01){
					if(a+b+c+d == a*b*c*d){
						cout << a << " " << b  << " " <<  c << " " << d << endl;
					}
				}
			}
		}
	}
	//cout << c << endl;
}
