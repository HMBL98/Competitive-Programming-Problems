#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
int N;
map<string,int> friends;
int cuenta = 0;
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
                        }else{
				cuenta++;
			}
                }
                int numDisjointSets(){ return numSets; }
                int sizeOfSet(int i){ return setSize[findSet(i)];}
};

int main(){
	optimizar_io;
	int caso = 0;
	while(cin >> N && N){
		UnionFind uf(N+1);
		int id1,id2, id = 0;
		string a,b;
		for(int i = 0; i < N; i++){
			cin >> a >> b;
			id1 = friends[a];
			if(!id1){
				friends[a] = ++id;
				id1 = id;
			}
			id2 = friends[b];
			if(!id2){
				friends[b] = ++id;
				id2 = id;
			}
			uf.unionSet(id1,id2);
		}
		cout << ++caso << " " << cuenta << endl;
		friends.clear();
		cuenta = 0;
	}
}

