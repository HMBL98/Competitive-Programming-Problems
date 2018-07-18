#include <iostream>
using std::cout;
using std::cin;
#include <utility> 
using std::pair;
#include <algorithm>
using std::sort;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+100
#define MOD 1000000007
int p[MAX],_rank[MAX],setSize[MAX],numSets;
typedef long long ll;
typedef pair<int,int> ii;
pair<ll,ii> edges[MAX];

void fastscan(int &number){
	bool negative = false;
    	register int c;
    	number = 0;
    	c = getchar();
    	if(c=='-'){
    		negative = true;
        	c = getchar();
    	}
   	for(; (c>47 && c<58); c=getchar())
        	number = number *10 + c - 48;
    	if(negative)
        	number *= -1;
}
void makeSet(int s){
	numSets = s;
	forn(i,0,s){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
void unionSet(int i,int j){
	int x = findSet(i);
	int y = findSet(j);
	if(x != y){
		numSets--;
		if(_rank[x] > _rank[y]){
			p[y] = x;
			setSize[x] += setSize[y];
		}else{
			p[x] = y;
			setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int N;

int main(){
	fastscan(N);
	forn(i,0,N-1){
		int x,y,c;
		fastscan(x); fastscan(y); fastscan(c);x--; y--;
		edges[i] = {c,{x,y}};
	}
	sort(edges,edges+N-1);
	makeSet(N);
	ll res = 0;
	ll part1;
	forn(i,0,N-1){
		pair<ll,ii> act = edges[i];
		ll s1 = setSize[findSet(act.second.first)];
		ll s2 = setSize[findSet(act.second.second)];
		if(s1 == 1 && s2 == 1){
			res = ((res%MOD)+(act.first%MOD))%MOD;
		}
		else if(s1 == 1){
			part1 = ((s2%MOD)*(act.first%MOD))%MOD;
			res = ((res%MOD)+(part1%MOD))%MOD;
		}
		else if(s2 == 1){
			part1 = ((s1%MOD)*(act.first%MOD))%MOD;
                        res = ((res%MOD)+(part1%MOD))%MOD;
		}else{
			part1 = ((s1%MOD)*(s2%MOD))%MOD;
			part1 = ((part1%MOD)*(act.first%MOD))%MOD;
			res = ((res%MOD)+(part1%MOD))%MOD;
		}
		unionSet(act.second.first,act.second.second);
	}
	cout << res << "\n";

}
