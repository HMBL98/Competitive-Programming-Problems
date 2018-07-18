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
	int x,y,cnt,lazy;
	Treap *l,*r;
	Treap(int x) : x(x), y(rand()), l(r = 0), cnt(1),lazy(0){}
};
int cnt(Treap *t){
	return t ? t->cnt : 0;
}
void update(Treap *t){
	if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void push(Treap *t){
	if(t){
		if(t->lazy)swap(t->l,t->r);
		if(t->l)t->l->lazy ^= t->lazy;
		if(t->r)t->r->lazy ^= t->lazy;
		t->lazy = 0;
	}
}
void split(Treap *t, Treap *&l, Treap *&r, int k){
	push(t);
	if(!t){l = r = 0; return;}
	if(cnt(t->l) >= k)split(t->l,l,t->l,k), r = t;
	else split(t->r,t->r,r,k-cnt(t->l)-1), l = t;
	update(t);
}
Treap *merge(Treap *l, Treap *r){
	push(l);
	push(r);

	if(!l) return r;
	if(!r) return l;

	if(l->y > r->y){
		l->r = merge(l->r,r);
		update(l);
		return l;
	}else{
		r->l = merge(l,r->l);
		update(r);
		return r;
	}

}
void out(Treap *t){
        if(!t)return;
        push(t);
        out(t->l);
        cout << t->x << " ";
        out(t->r);
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
	update(t);
}
void erase(Treap *&t,int i){
	if(!t)return;
	/*if(i == cnt(t->l)+1){
		Treap *tmp = merge(t->l,t->r);
		delete t;
		t = tmp;
	}else if(cnt(t->l) >= i)erase(t->l,i);
	else erase(t->r,i-cnt(t->l)-1);*/
	Treap *t1,*t2,*t3;
	split(t,t1,t3,i-1);
	split(t3,t2,t3,1);
	delete t2;
	t = merge(t1,t3);
	update(t);
}
int kth(Treap *t,int k){
	if(!t) return -1;
	if(k == cnt(t->l)+1) return t->x;
	if(cnt(t->l) >= k) return kth(t->l,k);
	return kth(t->r,k-cnt(t->l)-1);
}
void reverse(Treap *t,int l,int r){
	Treap *t1,*t2,*t3;
	split(t,t1,t2,l-1);
	split(t2,t2,t3,r-l+1);
	t2->lazy ^= 1;
	t = merge(t1,t2);
	t = merge(t,t3);
}
Treap *t = 0;
int n,m,l,r;
int main(){
	/*ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i,1,n+1)insert(t,new Treap(i),i);
	while(m--){
		cin >> l >> r;
		reverse(t,l,r);
	}
	out(t); cout << "\n";*/
	while(1){
                int opc,val,idx; cin >> opc;
                if(opc == 1){
                        cin >> val >> idx;
                        insert(t,new Treap(val),idx);
                }else if(opc == 2){
                        cin >> idx;
                        erase(t,idx);
                }else{
                        cin >> idx;
                        cout << kth(t,idx) << "\n";
                }
                out(t); cout << "\n";
        }
}
