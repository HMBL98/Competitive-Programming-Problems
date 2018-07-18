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
		Double anguloTmp = 0;
		Double anguloRes = 0;
		Double magRes;
		Double x = 0, y = 0;
		bool magAng = true;
		bool which = false;
		for(int i = 0; i < c; i++){
			string comando; string valor;
			cin >> comando >> valor;
			if(comando[0] == 'l'){
				if(valor[0] != '?'){
					anguloTmp += stoi(valor);
				}else{
					which = true;
					magAng = false;
				}
			}else if(comando[0] == 'r'){
				if(valor[0] != '?'){
					anguloTmp -= stoi(valor);
				}else{
					which = true;
					magAng = false;
				}
			}else if(comando[0] == 'f'){
				if(valor[0] != '?' && magAng){
					angulo += anguloTmp;
					anguloTmp = 0;
					x += stoi(valor)*cos(angulo*pi/180);
					y += stoi(valor)*sin(angulo*pi/180);
				}else{
					anguloRes = anguloTmp;
					anguloTmp = 0;
					magAng = true;
				}

			}else{
				if(valor[0] != '?' && magAng){
					angulo += anguloTmp;
					anguloTmp = 0;
					x -= stoi(valor)*cos(angulo*pi/180);
					y -= stoi(valor)*sin(angulo*pi/180);
				}else{
					anguloRes = anguloTmp;
					anguloTmp = 0;
					magAng = true;
				}
			}
		}
		if(!which){
			printf("%.lf\n", sqrt(x*x+y*y));
		}else{
			double angulo  =  fabs(atan(y/x)* 180 / pi);
			printf("%.lf\n",angulo);
		}
	}
}

