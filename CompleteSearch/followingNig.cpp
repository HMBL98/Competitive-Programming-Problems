#include <bits/stdc++.h>
using namespace std;

int movY[] = {1,-1,1,-1,2,-2,2,-2};
int movX[] = {2,2,-2,-2,1,1,-1,-1};

bool status;
void backtrack(int r,int c,int pos,int arreglo[][8]){
	if(pos == 63){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				if(j) cout << " ";
				cout << arreglo[i][j];
			}
			cout << endl;
		}
		cout << endl;
		status = true;
		return;
	}
	if(!status){
		int rn,cn;
		int arregloN[8][8];
		for(int i = 0; i < 8; i++){
			rn = r+movY[i];
			cn = c+movX[i];
			if(arreglo[rn][cn] == -1 && rn < 8 && rn >= 0 && cn < 8 && cn >= 0){
				//cout << pos+1 << endl;
				//cout << "Con" << rn << " " << cn << endl;
				for(int j = 0; j < 8; j++){
                                	for(int k = 0; k < 8; k++){
                                        	arregloN[j][k] = arreglo[j][k];
                                	}
                        	}
				arregloN[rn][cn] = pos;
				backtrack(rn,cn,pos+1,arregloN);
			}
		}
	}
}

int main(){
	int r,c;
	while(cin >> r >> c){
		int arreglo[8][8];
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				arreglo[i][j] = -1;
			}
		}
		arreglo[0][0] = 0;
		status = false;
		backtrack(0,0,1,arreglo);
	}
}
