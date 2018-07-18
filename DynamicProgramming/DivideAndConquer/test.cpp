#include <iostream>
using namespace std;

int main(){
	cout << 4000 << " " << 10 << endl;
	for(int i = 1; i <= 4000; i++){
		for(int j = 1; j <= 4000; j++)
			cout << 1 << " ";
		cout << endl;
	}
}
