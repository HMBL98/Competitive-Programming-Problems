#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;
using std::ios_base;
#include <cstring>
using std::strcpy;
struct info{
	char name[25];
	int x,y;
};
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

info array[10000+100];
int T,D,Q;
int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		cin >> D;
		for(int i = 0; i < D; i++){
			cin >> array[i].name; cin >> array[i].x; cin >> array[i].y;
		}
		cin >> Q;
		int tmp;
		int c;
		char nombre[25];
		for(int i = 0; i < Q; i++){
			cin >> tmp;
			c = 0;
			for(int j = 0; j < D && c < 2; j++){
				if(array[j].x <= tmp && array[j].y >= tmp){
					c++;
					strcpy(nombre,array[j].name);
				}
			}
			if(c == 1){
				cout << nombre << endl;
			}else{
				cout << "UNDETERMINED" << endl;
			}
		}
		if(T != 0) cout << endl;
	}
}
