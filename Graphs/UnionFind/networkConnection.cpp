#include <bits/stdc++.h>
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
	int T;
	cin >> T;
	while(T--){
		char c;
		int n;
		cin >> n;
		UnionFind uf(n+1);
		int s = 0,us = 0;
		string line;
		int a,b;
		cin.ignore();
		cin.clear();
		while(getline(cin,line)){
			if(line.empty()){
				break;
			}
			sscanf(line.c_str(),"%c %d %d",&c,&a,&b);
			if(line[0] == 'c'){
				uf.unionSet(a,b);
			}else{
				if(uf.isSameSet(a,b)){
					s++;
				}else{
					us++;
				}
			}
		}
		cout << s << "," << us << endl;
		if(T > 0){
			cout << endl;
		}
		
	}

}
