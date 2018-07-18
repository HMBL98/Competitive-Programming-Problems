#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000+100

class SegmentTree{
	public:
	int tree[4*MAX],A[MAX];
	void build(int node, int start, int end){
		if(start == end){
        		// Leaf node will have a single element
        		tree[node] = A[start];
	    	}else{
        		int mid = (start + end) / 2;
        		// Recurse on the left child
	        	build(2*node, start, mid);
        		// Recurse on the right child
        		build(2*node+1, mid+1, end);
	        	// Internal node will have the sum of both of its children
        		tree[node] = max(tree[2*node],tree[2*node+1]);
    		}
	}
	void update(int node, int start, int end, int idx, int val){
		if(start == end){
        		// Leaf node
	        	A[idx] = val;
        		tree[node] = val;
	    	}else{
        		int mid = (start + end) / 2;
        		if(start <= idx and idx <= mid){
	            		// If idx is in the left child, recurse on the left child
        	    		update(2*node, start, mid, idx, val);
        		}else{
	            		// if idx is in the right child, recurse on the right child
        	   		update(2*node+1, mid+1, end, idx, val);
        		}
	        	// Internal node will have the sum of both of its children
        		tree[node] = max(tree[2*node],tree[2*node+1]);
	    	}
	}
	int query(int node, int start, int end, int l, int r){
		if(r < start or end < l){
	        	// range represented by a node is completely outside the given range
			// Be careful
        		return -1;
	    	}
    		if(l <= start and end <= r){
	        	// range represented by a node is completely inside the given range
        		return tree[node];
	    	}
    		// range represented by a node is partially inside and partially outside the given range
	    	int mid = (start + end) / 2;
    		int p1 = query(2*node, start, mid, l, r);
	    	int p2 = query(2*node+1, mid+1, end, l, r);
		return max(p1,p2);
	}
};
int n,m,k;
SegmentTree seg[5];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	forn(i,1,n+1){
		forn(j,0,m){
			cin >> seg[j].A[i];
		}
	}
	forn(i,0,m)seg[i].build(1,1,n);
	function<bool(int)> possible = [&](int mit){
		int counter;
		forn(i,1,n-mit+2){
			counter = 0;
			forn(j,0,m){
				counter += seg[j].query(1,1,n,i,i+mit-1);
			}
			if(k >= counter)return true;
		}
		return false;
	};
	int ini = 0,fin = n+1;
	while(ini < fin){
		int mit = (ini+fin)>>1;
		if(!possible(mit))fin = mit;
		else ini = mit+1;
	}
	ini--;
	forn(i,1,n-ini+2){
        	int counter = 0;
		vector<int> res;
              	forn(j,0,m){
			int q = seg[j].query(1,1,n,i,i+ini-1);
                        counter += q;
			res.push_back((q < 0) ? 0 : q);
                }
		if(k >= counter){
			for(auto &x : res)cout << x << " ";
			return 0;
		}
	}
}
