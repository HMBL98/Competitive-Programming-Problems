#include <iostream>
#include <vector>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;

class UnionFind{
	private:
		vi p,rank,setSize;
		int numSets;
	public:
		UnionFind(int N){
			setSize.assign(N,1); numSets = N; rank.assign(N,0);
			p.assign(N,0); 
			for(int i = 0; i < N; i++){ p[i] = i;}
		}
		int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
		bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				numSets--;
				int x = findSet(i), y = findSet(j);

				if(rank[x] > rank[y]){
					p[y] = x; setSize[x] += setSize[y];
				}else{
					p[x] = y; setSize[y] += setSize[x];
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
		int numDisjointSets(){ return numSets; }
		int sizeOfSet(int i){ return setSize[findSet(i)];}
};
int main(){
	optimizar_io;
	int n,m,anios;
	int * prendi;
	string prendidas;
	
	while(cin >> n){
		UnionFind uf(26);
		cin >> m;
		cin >> prendidas;
		anios = 0;
		prendi = new int[26];
		for(int i = 0; i < prendidas.size(); i++){
			prendi[prendidas[i]-'A'] = 1;
		}
		for(int i = 0; i < m; i++){
			string par;
			cin >> par;
			int cuantos = 0;
			uf.unionSet(par[0]-'A',par[1]-'A');
			for(int j = 0; j < prendidas.size(); j++){
				if(!prendi[par[0]-'A'] && uf.isSameSet(par[0]-'A',prendidas[j]-'A')){
					cuantos++;
				}
			}
			if(cuantos >= 3){
				anios++;
				prendidas += par[0];
				prendi[par[0]-'A'] = 1;
			}
		}
		//cout << prendidas << endl;
		//cout << prendidas.size() << endl;
		if(prendidas.size() == n){
			cout << "WAKE UP IN, " <<  anios << ", YEARS" << endl;
		}else{
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
	}
}

