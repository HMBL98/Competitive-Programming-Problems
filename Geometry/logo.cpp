#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int t,c;
typedef double Double;
int main(){
	optimizar_io;
	cin >> t;
	Double pi = 2*acos(0.0);
	while(t--){
		cin >> c;
		Double angulo = 0;
		Double x = 0, y = 0;
		for(int i = 0; i < c; i++){
			string comando;	Double valor;
			cin >> comando >> valor;
			if(comando[0] == 'l'){
				angulo += valor;
				//if(angulo >= 360)angulo -= 360;
			}else if(comando[0] == 'r'){
				angulo += 360-valor;
				//if(angulo < 0) angulo += 360;
			}else if(comando[0] == 'f'){
				x += valor*cos(angulo*pi/180);
				y += valor*sin(angulo*pi/180);
				//cout << tmp.x << "i + " <<  tmp.y << "j" << endl;

			}else{
				x -= valor*cos(angulo*pi/180);
				y -= valor*sin(angulo*pi/180);
				//cout << tmp.x << "i + " <<  tmp.y << "j" << endl;
			}
		}
		printf("%.lf\n", sqrt(x*x+y*y));
	}
}

