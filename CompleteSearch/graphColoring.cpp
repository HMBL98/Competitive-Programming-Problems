#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int t,n,v;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> lista;
set<int> res;
int mayor;

void backtrack(int pos,set<int> negros, bitset<100+10> visited){
	if(visited.count() == n /*&& (int)negros.size() > mayor*/){
		mayor = negros.size();
		cout << negros.size() << endl;
		for(set<int>::iterator it = negros.begin(); it != negros.end(); it++){
                        cout << *it << " ";
                }
		cout << endl;
		res = negros;
		return;

	}
	set<int> negrosT;
	bitset<100+10> visitedT;
	for(int i = pos; i <= n; i++){
		negrosT = negros; visitedT = visited;
		if(!visitedT[i]){
			bool status  = true;
			for(int k = 0; k < lista[i].size(); k++){
				if(negrosT.find(lista[i][k].first) != negrosT.end()){
					status = false; break;
				}
			}
			if(status){
				negrosT.insert(i);
				visitedT[i] = 1;
			}else{
				visitedT[i] = 1;
			}
			backtrack(pos+1,negrosT,visitedT);
		}
	}
}
int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> n >> v;
		lista.assign(n+1,vii());
		for(int i = 0; i < v; i++){
			int s,d; cin >> s >> d;
			lista[s].push_back({d,0});
			lista[d].push_back({s,0});
		}
		set<int> a;bitset<100+10> b;
		mayor = -1;
		backtrack(1,a,b);
		/*cout << res.size() << endl;
		int i = 0;
		for(set<int>::iterator it = res.begin(); it != res.end(); it++,i++){
			if(i) cout << " ";
			cout << *it;
		}
		cout << endl;*/
		lista.clear();
	}
}
