#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
int T;
int f;
map<string,int> friends;
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
		int unionSet(int i, int j){
			int x = findSet(i), y = findSet(j);
			if(x != y){
				numSets--;
				if(rank[x] > rank[y]){
					p[y] = x; setSize[x] += setSize[y];
					return setSize[x];
				}else{
					p[x] = y; setSize[y] += setSize[x];
					if(rank[x] == rank[y]) rank[y]++;
					return setSize[y];
				}
			}
			return setSize[findSet(i)];
		}
		int numDisjointSets(){ return numSets; }
		int sizeOfSet(int i){ return setSize[findSet(i)];}
};

int main(){
	optimizar_io; 
	cin >> T;
	string a,b;
	int id1,id2;
	while(T--){
		cin >> f;
		UnionFind uf(min(2*f, 100000));
		int id = 0;
		for(int i = 0; i < f; i++){
			cin >> a >> b;
			id1 = friends[a];
			if(id1 == 0){
				friends[a] = ++id;
				id1 = id;
			}
			id2 = friends[b];
			if(id2 == 0){
				friends[b] = ++id;
				id2 = id;
			}
			cout << uf.unionSet(id1,id2) << endl;
		}
		friends.clear();
	}
}

