#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
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
	int n;
	cin >> n;
	while(n--){
		UnionFind uf(26);
		set<int>usadas;

		string cadena;
		while(cin >> cadena){
			if(cadena[0] == '*') break;
			uf.unionSet(cadena[1]-'A',cadena[3]-'A');

		}
		cin >> cadena;
		int ntress = 0;
		int nacorns = 0;

		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] != ',' && usadas.find(uf.findSet(cadena[i]-'A')) == usadas.end()){
				usadas.insert(uf.findSet(cadena[i]-'A'));
				if(uf.sizeOfSet(uf.findSet(cadena[i]-'A')) > 1){
					ntress++;
				}else{
					nacorns++;
				}
			}
		}
		cout << "There are " << ntress << " tree(s) and " << nacorns << " acorn(s)." << endl;
	}
}
