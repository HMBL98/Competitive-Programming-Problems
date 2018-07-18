#include <bits/stdc++.h>
using namespace std;

vector<int> folders;
int workers;
int predicado(int size){
            int suma = 0;
            int cuantos = 0;
            for(int i = 0; i < folders.size(); i++){
                if(suma + folders[i] <= size){
                        suma += folders[i];
                }else{
			cuantos++;
                    	suma = folders[i];
                }
            }
            cuantos++;
            return cuantos;
}
int main(){
	int n;
	while(cin >> n >> workers){
		for(int i = 0; i < n; i++){
			int tmp; cin >> tmp;
			folders.push_back(tmp);
		}
            	/*long long ini = *max_element( folders.begin(), folders.end() );
		long long fin =accumulate( folders.begin(), folders.end(), 0 );*/
		long long ini = 0;
		long long fin = 1e5;
		//cout << ini << " " << fin << endl;
           	while(ini < fin){
               		long long mitad = (ini+fin)/2;
			cout << mitad << " " << predicado(mitad) << endl;
           		if(predicado(mitad) <= workers){
                		fin = mitad;
                	}else{
                		ini = mitad+1;
                	}
            	}
        	cout << ini << endl;

        }
}
