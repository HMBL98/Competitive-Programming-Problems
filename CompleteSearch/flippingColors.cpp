#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

double iniX,iniY;
double H,V,h,v;
int n,caso;
double x,y;
bool black;

void backtrack(){
	double x1 = H*h; double y1 = V*v;
	if((x > x1 && y < y1) || (x < x1 && y > y1)){
		if(black) cout << "black" << endl;
		else cout << "white" << endl;
	}else{
		black = (black) ? false : true;
		if(x < x1 && y < y1){
			H = x1; V = y1;
		}else{
			H = H*(1-h); V = V*(1-v);
			x-=x1; y-= y1;
		}
		backtrack();
	}
}
int main(){
	optimizar_io;
	caso = 0;
	double Htmp, Vtmp;
	while(cin >> Htmp >> Vtmp >> h >> v && Htmp){
		cin >> n;
		cout << "Case " << ++caso << ":" << endl;
		for(int i = 0; i < n; i++){
			H = Htmp; V = Vtmp; black = true;
			iniX = iniY = 0.0;
			cin >> x >> y;
			backtrack();
		}
	}
	return 0;
}
