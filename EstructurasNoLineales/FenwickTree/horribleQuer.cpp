#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+10

typedef long long int ll;
ll bit[MAX],bit2[MAX],N,Q;

//Range updates and Range queries
ll query(int opc,int idx){
        ll sum = 0;
        while(idx > 0){
		if(opc) sum += bit[idx];
		else sum += bit2[idx];
                idx -= idx&-idx;
        }
        return sum;
}
//Return sum A[1....idx]
ll query(int idx){
	return query(1,idx)*idx-query(0,idx);
}
//Return sum A[idx....idy] 
ll sum(int idx,int idy){
	return query(idy)-query(idx-1);
}
void _update(int opc,int idx,ll val){
        //tener cuidado con N+1
        while(idx < N+1){
		if(opc) bit[idx] += val;
		else bit2[idx] += val;
                idx += idx&-idx;
        }
}
//Add v to A[a...b] 
void update(int idx,int idy,ll val){
	_update(1,idx,val);
	_update(1,idy+1,-val);
	_update(0,idx,val*(idx-1));
	_update(0,idy+1,-val*idy);
}
int t;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> N >> Q;
		forn(i,0,N+10)bit[i] = bit2[i] = 0;
		while(Q--){
			int opc; cin >> opc;
			if(opc == 0){
				int l,r,val; cin >> l >> r >> val;
				update(l,r,val);
			}else{
				int l,r; cin >> l >> r;
				cout << sum(l,r) << "\n";
			}
		}
	}
}

