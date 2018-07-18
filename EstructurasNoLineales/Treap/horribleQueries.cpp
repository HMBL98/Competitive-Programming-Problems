#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Treap{
	int y,cnt;
	ll sum,lazy,x;
	Treap *l,*r;
	Treap(ll x) : x(x), y(rand()), l(r = 0), cnt(1),lazy(0),sum(x){}
};
int gcnt(Treap *t){
	return t ? t->cnt : 0;
}
int gsum(Treap *t){
	return t ? t->sum : 0;
}
void push(Treap *t){
        if(t){
		if(t->lazy){
			t->x += t->lazy;
			t->sum += t->lazy*gcnt(t);
		}
                if(t->l)t->l->lazy += t->lazy;
                if(t->r)t->r->lazy += t->lazy;
                t->lazy = 0;
        }
}
void reset(Treap *t){
	if(t)t->sum = t->x;
}
void combine(Treap *&t,Treap * l,Treap *r){
	if(!l || !r)return void(t = l?l:r);
	t->sum = gsum(l)+gsum(r);
}
void operation(Treap *t){
	if(!t)return;
    	reset(t);
    	push(t->l);push(t->r);
    	combine(t,t->l,t);
    	combine(t,t,t->r);
}
void updatecnt(Treap *t){
	if(t){
		t->cnt = 1 + gcnt(t->l) + gcnt(t->r);
	}
}
void split(Treap *t, Treap *&l, Treap *&r, int k){
	push(t);
	if(!t){l = r = 0; return;}
	if(gcnt(t->l) >= k)split(t->l,l,t->l,k), r = t;
	else split(t->r,t->r,r,k-gcnt(t->l)-1), l = t;
	updatecnt(t);
	operation(t);
}
Treap *merge(Treap *l, Treap *r){
	push(l);
	push(r);
	if(!l) return r;
	if(!r) return l;

	if(l->y > r->y){
		l->r = merge(l->r,r);
		updatecnt(l);
		operation(l);
		return l;
	}else{
		r->l = merge(l,r->l);
		updatecnt(r);
		operation(r);
		return r;
	}

}
void insert(Treap *&t, Treap *n,int i){
	push(t);
	if(!t) t = n;
	else{
		Treap *t1,*t2;
		split(t,t1,t2,i-1);
		t = merge(t1,n);
		t = merge(t,t2);
	}
	updatecnt(t);
}
void out(Treap *t){
        if(!t)return;
     	push(t);
        out(t->l);
        cout << t->x << " ";
        out(t->r);
}
void range_update(Treap *t,int l,int r,int val){
	Treap *t1,*t2,*t3;
	split(t,t1,t2,l-1);
	split(t2,t2,t3,r-l+1);
	t2->lazy += val;
	t = merge(t1,t2);
	t = merge(t,t3);
}
ll range_query(Treap *t,int l,int r){
	Treap *t1,*t2,*t3;
	split(t,t1,t2,l-1);
	split(t2,t2,t3,r-l+1);
	ll res = gsum(t);
	t = merge(t1,t2);
	t = merge(t,t3);
	return res;
}
Treap *t = 0;
int n,m,l,r,val;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,1,n+1){
		insert(t,new Treap(i),i);
	}
	out(t); cout << "\n";
	while(m--){
		int opc; cin >> opc;
		if(opc == 0){
			cin >> l >> r >> val;
			range_update(t,l,r,val);
		}else{
			cin >> l >> r;
			cout << range_query(t,l,r) << "\n";
		}
		out(t); cout << "\n";
	}
	return 0;
}
