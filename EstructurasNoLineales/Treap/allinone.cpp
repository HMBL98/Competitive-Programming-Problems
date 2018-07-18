#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Treap{
	int x,y,cnt;
	Treap *l,*r;
	Treap(ll x) : x(x), y(rand()), l(r = 0), cnt(1){}
};

ll cnt(Treap *t){
	return t ? t->cnt : 0;
}
void updatecnt(Treap *t){
	if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void split(Treap *t, Treap *&l, Treap *&r, ll x){
	if(!t){l = r = 0; return;}
	if(x <= t->x) split(t->l,l,t->l,x), r = t;
	else split(t->r,t->r,r,x), l = t;
	updatecnt(t);
}
Treap *merge(Treap *l, Treap *r){
	if(!l) return r;
	if(!r) return l;

	if(l->y > r->y){
		l->r = merge(l->r,r);
		updatecnt(l);
		return l;
	}else{
		r->l = merge(l,r->l);
		updatecnt(r);
		return r;
	}

}
void insert(Treap *&t, Treap *n){
	if(!t) t = n;
	else if(n->y > t->y) split(t,n->l,n->r,n->x), t = n;
	else insert(n->x < t->x ? t->l : t->r,n);
	updatecnt(t);
}
void erase(Treap *&t,ll x){
	if(t && t->x == x){
		Treap *tmp = merge(t->l,t->r);
		delete t;
		t = tmp;
	}else if(t){
		erase(x < t->x ? t->l : t->r, x);
	}
	updatecnt(t);
}
ll binSearch(Treap *t,ll x){
	if(!t) return 0;
	if(t->x  > x) return binSearch(t->l,x);
	return cnt(t->l)+1+binSearch(t->r,x);
}
ll kth(Treap *t,ll k){
	if(!t) return -1;
	if(k == cnt(t->l)+1) return t->x;
	if(cnt(t->l) >= k) return kth(t->l,k);
	return kth(t->r,k-cnt(t->l)-1);
}
Treap *t = 0;
ll opc,val;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(1){
		cin >> opc;
		if(opc == 1){
			cin >> val;
			if(!t)t = new Treap(val);
			else insert(t,new Treap(val));
		}else if(opc == 2){
			cin >> val;
			erase(t,val);
		}else if(opc == 3){
			cin >> val;
			ll bin = binSearch(t,val);
			if(kth(t,bin) == val)cout << bin << "\n";
			else  cout << "-1\n";
		}else if(opc == 4){
			cin >> val;
			cout << kth(t,val) << "\n";
		}else break;
	}
	return 0;
}
