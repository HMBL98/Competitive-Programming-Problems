#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> ii;

int main(){
	optimizar_io;
	int N,p;
	vector<ii> vecinos;
	cin >> N;
	while(N--){
		cin >> p;
		vecinos.assign(p,ii());
		cin.ignore();
		cin.clear();
		for(int i = 0; i < p; i++){
			string tmp;
			getline(cin,tmp);
			int v = 1;
			for(int j = 0; j < tmp.size(); j++){
				if(tmp[j] == ' ') v++;
			}
			vecinos[i].first =  v;
			vecinos[i].second = i+1;
		}
		sort(vecinos.begin(),vecinos.end());
		/*for(int i = 0; i < p; i++){
			cout << vecinos[i].second << " " << vecinos[i].first << endl;
		}*/
		int menor = vecinos[0].first;
		cout << vecinos[0].second;
		for(int i = 1; i < p && vecinos[i].first == menor; i++){
			cout << " " << vecinos[i].second;
		}
		cout << endl;
	}
}
