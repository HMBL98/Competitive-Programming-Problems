#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define MAX 1000000+10

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
		int x = findSet(i),y = findSet(j);
		if(_rank[x] > _rank[y]){
			p[y] = x; setSize[x] += setSize[y];
		}else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[y] == _rank[x])_rank[y]++;
		}
	}
}
int n,m,x,y;
char c;
int main(){
	optimizar_io;
	cin >> n >> m;
	makeSet(n);
	for(int i = 0; i < m; i++){
		cin >> c;
		if(c == 'A'){
			cin >> x >> y;
			x--; y--;
			unionSet(x,y);
		}else{
			cin >> x; x--;
			cout << setSize[findSet(x)] << "\n"; 
		}
	}
}
