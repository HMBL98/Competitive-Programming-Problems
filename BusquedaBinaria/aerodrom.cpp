#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <long long> desk;
int main(){
	long long n,m;
	cin >> n >> m;
	for(long long i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		desk.push_back(tmp);
	}
	long long ini = 1;
	long long fin = 1LL<<60;
	long long ans = 0;
	while(ini <= fin){
		long long mitad = (ini+fin)/2;
		long long personas = 0;
		for(long long i = 0; i < n; i++){
				personas += (mitad/desk[i]);
		}
	//	cout << "con " << mitad << " tenemos " << personas << endl;

		if(personas < m){
			ini = mitad+1;
		}else{
			fin = mitad-1;
			ans = mitad;
		}
	}
	cout << ans << endl;
}

