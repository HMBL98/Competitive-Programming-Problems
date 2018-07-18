#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10

int p[MAX],_rank[MAX],setSize[MAX],numSets;

void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}

int main(){
	int x,y,res;
	makeSet(100000+10);
	while(cin >> x){
		if(x == -1){
			cout << res << "\n";
			makeSet(100000+10);
			res = 0;
		}else{
			cin >> y;
			if(!isSameSet(x,y)) unionSet(x,y);
			else res++;
		}
	}

}
