#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <math.h>

long long sum(int n){
	return (n*(n+1))/2;
}
int main(){
	long long n;
	cin >> n;
	for(int i = 1; i <= sqrt(n) ; i++){
		int n1 = n - sum(i);
		n1*=2;
//		int n2 = (-1+sqrt(1-4*(-1)*(n1) ))/2;
		int n2 = sqrt(n1);
	
		if(n2 > 0 && sum(n2)*2 == n1){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
