#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
int main(){
	optimizar_io;
	vector<vi> list;
	int n,m;
	while(cin >> n >> m){
		list.assign(1000500,vi());
		for(int i = 1; i <= n; i++){
			int tmp;
			cin >> tmp;
			list[tmp].push_back(i);
		}
		for(int i = 0; i < m; i++){
			int k,v;
			cin >> k >> v;
			if(list[v].size() == 0 || list[v].size() < k){
				cout << "0" << endl;
			}else{
				cout << list[v][k-1] << endl;
			}

		}
	}
}
