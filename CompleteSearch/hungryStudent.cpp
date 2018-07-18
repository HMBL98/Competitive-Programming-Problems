#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
	optimizar_io;
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		bool status = false;
		for(int i = 0; i < 15; i++){
			if(7*i > x) break;
			int tmp = (x-7*i)/3;
			if((3*tmp+7*i) == x){
				//cout << tmp << " " << i << endl;
				status = true;
				break;
			}
		}
		if(status){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
