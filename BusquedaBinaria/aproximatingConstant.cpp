#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
	private:
		vi st, A;            // recall that vi is: typedef vector<int> vi;
		vi st2;
  		int n;
  		int left (int p) { return p << 1; }     // same as binary heap operations
  		int right(int p) { return (p << 1) + 1; }
		void build(int p, int L, int R) {                           // O(n log n)
    			if(L == R){                            // as L == R, either one is fine
      				st[p] = L;                                         // store the index
				st2[p] = L;
    			}else{                                // recursively compute the values
      				build(left(p) , L              , (L + R) / 2);
      				build(right(p), (L + R) / 2 + 1, R          );
      				int p1 = st[left(p)], p2 = st[right(p)];
      				st[p] = (A[p1] <= A[p2]) ? p1 : p2;
				p1 = st2[left(p)], p2 = st2[right(p)];
			       	st2[p] = (A[p1] <= A[p2]) ? p2 : p1;
  			}
		}
		int rmq2(int p, int L, int R, int i, int j) {                  // O(log n)
                        if (i >  R || j <  L) return -1; // current segment outside query range
                        if (L >= i && R <= j) return st2[p];               // inside query range
                        // compute the min position in the left and right part of the interval
                        int p1 = rmq2(left(p) , L              , (L+R) / 2, i, j);
                        int p2 = rmq2(right(p), (L+R) / 2 + 1, R          , i, j);
                        if (p1 == -1) return p2;   // if we try to access segment outside query
                        if (p2 == -1) return p1;                               // same as above
                        return (A[p1] <= A[p2]) ? p2 : p1; 
                }
  		int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    			if (i >  R || j <  L) return -1; // current segment outside query range
    			if (L >= i && R <= j) return st[p];               // inside query range
     			// compute the min position in the left and right part of the interval
    			int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    			int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);
    			if (p1 == -1) return p2;   // if we try to access segment outside query
	    		if (p2 == -1) return p1;                               // same as above
    			return (A[p1] <= A[p2]) ? p1 : p2; 
		}          // as as in build routine
  		int update_point(int p, int L, int R, int idx, int new_value) {
    			// this update code is still preliminary, i == j
    			// must be able to update range in the future!
    			int i = idx, j = idx;
		    	// if the current interval does not intersect 
    			// the update interval, return this st node value!
    			if (i > R || j < L)
      				return st[p];
    			// if the current interval is included in the update range,
    			// update that st[node]
    			if (L == i && R == j) {
      				A[i] = new_value; // update the underlying array
      				return st[p] = L; // this index
   	 		}
    			// compute the minimum pition in the 
    			// left and right part of the interval
    			int p1, p2;
    			p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    			p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);
    			// return the pition where the overall minimum is
    			return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	public:
 		SegmentTree(const vi &_A) {
    			A = _A; n = (int)A.size();              // copy content for local usage
    			st.assign(4 * n, 0);            // create large enough vector of zeroes
			st2.assign(4*n,0);
    			build(1, 0, n - 1);                                  // recursive build
  		}
  		int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading
		int rmq2(int i, int j) { return rmq2(1, 0, n - 1, i, j); }
		int update_point(int idx, int new_value) {
    		return update_point(1, 0, n - 1, idx, new_value); }
};
int n;
vector<int> numeros;

int main(){
	optimizar_io;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		numeros.push_back(tmp);
	}
	SegmentTree st(numeros);
	int ini = 1, fin = n+10;
	while(ini < fin){
		int mitad = (ini+fin)/2;
		bool status = false;
		for(int i = 0; i <= n-mitad; i++){
			if(numeros[st.rmq2(i,i+mitad-1)]-numeros[st.rmq(i,i+mitad-1)] <= 1){
				//cout << mitad << "-->" << i << " " << i+mitad-1 << endl;
				status = true;
				break;
			}
		}
		//cout << mitad << " " << status << endl;
		if(status){
			ini = mitad+1;
		}else{
			fin  = mitad;
		}
	}
	cout << ini-1 << endl;
}
