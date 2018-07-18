#include <cmath>
#include <cstdio>
using namespace std;

int p,q,r,s,t,u;
const double ERROR = 1e-6;
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

double solveit(double x){
	return (double)(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u);
}

int main(){
	double ini,fin;
	double mitad;
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6){
		/* if(solveit(1)>1e-9 || p+r+u<0){
            printf("No solution\n");
            continue;
        }*/
		 ini=0.0; fin=1.0;
		for(int i = 0; i < 30; i++){
			mitad = (ini+fin)/2;
			if(solveit(mitad) > 0){
				ini = mitad;
			}else{
				fin = mitad;
			}
		}
		if(!EQ(0,solveit(mitad))){
			printf("No solution\n");
		}else{
			printf("%.4f\n",mitad);
		}
	}
	return 0;
}
