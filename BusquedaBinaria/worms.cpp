#include <cstdio>
using std::printf;
using std::scanf;
#include <vector>
using std::vector;
#include <iostream>
using namespace std;
int main(){
	int n,m;
	vector<int> n1;

	scanf("%d",&n);
	n1.push_back(0);
	int anterior = 0;
	for(int i = 0; i < n; i++){
		int tmp;
		scanf("%d",&tmp);
		n1.push_back(anterior+tmp);
		anterior = anterior+tmp;
	}
	/*for(int i = 0; i < n1.size(); i++){
		printf("%d\n",n1[i]);
	}*/
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int tmp;
		scanf("%d",&tmp);

		int ini = 1, fin = n;
		while(ini <= fin){
			int mitad = (ini+fin)/2;
			/*cout << "***************" << endl;
			cout << ini << endl;
			cout << fin << endl;
			cout << mitad << endl;
			cout << n1[mitad-1] << endl;
			cout << n1[mitad] << endl;	*/
			if(tmp > n1[mitad-1] && tmp <= n1[mitad]){
				printf("%d\n",mitad);
				break;
			}
			if(tmp <= n1[mitad-1]){
				fin = mitad-1;
			}
			if(tmp >= n1[mitad]){
				ini = mitad+1;
			}
		}
	}
}
