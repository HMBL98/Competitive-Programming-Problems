#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <iomanip>
using std::setprecision;
#include <algorithm>
using std::sort;

vector <int> planetas;


double sumFuerzas(double pos){
	double sum = 0;
	for(int i = 0; i < planetas.size(); i++){
		sum += 1/(planetas[i]-pos);
	}
	return sum;
}
double busqueda(double ini,double fin){
	double mitad = 0;
	for(int i = 0; i < 25; i++){
		mitad = ((double)ini+fin)/2;
		double sum = sumFuerzas(mitad);
		if(sum > 0){
			fin = mitad;
		}else{
			ini = mitad;
		}
	}
	return mitad;

}


int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		planetas.push_back(tmp);
	}
	sort(planetas.begin(),planetas.begin()+n);
	cout << n-1 << endl;
	for(int i = 0; i < n-1; i++){
		//cout << setprecision(3) << busqueda(planetas[i],planetas[i+1]) << " ";
		printf("%.3lf ",busqueda(planetas[i],planetas[i+1]));
	}
	cout << "\n";
}
