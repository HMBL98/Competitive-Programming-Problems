#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_map>
using std::cout;
using std::cin;
using std::pair;
using std::sort;
using std::unordered_map;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+100
typedef pair<int,int> ii;
typedef long long ll;

int p[MAX],_rank[MAX],setSize[MAX],numSets,N,Q;
pair<ll,ii> edges[MAX];
unordered_map<int,int> mapper;
ll res[MAX];

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

int main(){
	fastscan(N); fastscan(Q);
	forn(i,0,N-1){
		int x,y,c;
		fastscan(x); fastscan(y); fastscan(c);x--; y--;
		edges[i] = {c,{x,y}};
	}
	sort(edges,edges+N-1);
	makeSet(N);
	int idx = 0;
	forn(i,0,N-1){
		pair<ll,ii> act = edges[i];
		ll s1 = setSize[findSet(act.second.first)];
		ll s2 = setSize[findSet(act.second.second)];
		int tmp = 0;
		if(!mapper[act.first]) mapper[act.first] = tmp = ++idx;
		else tmp = mapper[act.first];
		//cout << act.first << " " << tmp << "\n";
		if(s1 == 1 && s2 == 1){
			res[tmp] += 1;
		}else if(s1 == 1){
			res[tmp] += s2;
		}else if(s2 == 1){
			res[tmp] += s1;
		}else{
			res[tmp] += s1*s2;
		}
		res[tmp] += res[tmp-1];
		unionSet(act.second.first,act.second.second);
	}
	while(Q--){
		int l,r; cin >> l >> r;
		if(!mapper[l]){
			auto itlow = mapper.lower_bound(l);
			l = (--itlow)->second;
		}else l = mapper[l];
		if(!mapper[r]){
			auto itlow = mapper.lower_bound(r);
			r = (--itlow)->second;
		}else r = mapper[r];
		//cout << r << " "<< l << "\n";
		if(res[r] == 0)cout << 0 << "\n";
		else cout << res[r]-res[l-1] << "\n";
	}
}
