#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int main(){
	vector<ii> vii;
	int n;
	cin >> n;
	vii.assign(n,ii());
	for(int i = 0; i < n; i++){
		cin >> vii[i].first >> vii[i].second;
	}
	sort(vii.begin(),vii.end());
	int l,r;
	while(cin >> l >> r){
		int ini = 0, fin = vii.size()-1;
		int mitad;
                while(ini <= fin){
                        mitad = (ini+fin)/2;
                        if(l <= vii[mitad].first && r >= vii[mitad].second){
                                cout << "Found at " << mitad << endl;
                        }
                        if(l <= vii[mitad].first && r <= vii[mitad].second){
                                fin = mitad-1;
                        }else{
                                ini = mitad+1;
                        }
                }
	}
}
