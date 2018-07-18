#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int t,n;
int grid[10][10];

int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		int usadas = 0;
		int res = 0;
		for(int i = 0; i < n; i++){
			int menor = 1000000;
			int indice;
			for(int j = 0; j < n; j++){
				if(!(usadas & (1<<j))){
					if(grid[i][j] < menor){
						menor = grid[i][j];
						indice = j;
					}
				}
			}
			res += menor;
			usadas |= 1<<indice;
		}
		cout << res << endl;
	}
}
