#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int T,n;
int array[1000+100];
int res;
int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		cin >> n; res = 0;

		for(int i = 0; i < n; i++) cin >> array[i];
		for(int i = 1; i < n; i++){
			int c = 0;
			for(int j = 0; j < i; j++){
				if(array[j] <= array[i])c++;
			}
			res+=c;
		}
		cout << res << endl;
		
	}
}
