#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a, i >= b; i--)
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;
const ld PI = acos(-1.0);

vcd fft(const vcd &A){
	int n = A.size();
  	int k = 0;
  	while((1 << k) < n)k++;
  	vector<int> rev(n);
  	rev[0] = 0;
  	int high1 = -1;
  	for(int i = 1; i < n; i++){
    		if((i & (i - 1)) == 0)high1++;
    		rev[i] = rev[i ^ (1 << high1)];
    		rev[i] |= (1 << (k - high1 - 1));
  	}
  	vcd roots(n);
  	for(int i = 0; i < n; i++){
    		double alpha = 2 * PI * i / n;
    		roots[i] = cd(cos(alpha), sin(alpha));
  	}
  	vcd cur(n);
  	for(int i = 0; i < n; i++)cur[i] = A[rev[i]];
	for(int len = 1; len < n; len <<= 1){
    		vcd ncur(n);
    		int rstep = roots.size() / (len * 2);
    		for(int pdest = 0; pdest < n;){
      			int p1 = pdest;
      			for(int i = 0; i < len; i++){
        			cd val = roots[i * rstep] * cur[p1 + len];
        			ncur[pdest] = cur[p1] + val;
        			ncur[pdest + len] = cur[p1] - val;
        			pdest++, p1++;
      			}
      			pdest += len;
    		}
    		cur.swap(ncur);
  	}
	return cur;
}
vcd fft_rev(const vcd &A){
	vcd res = fft(A);
  	for(int i = 0; i < (int)res.size(); i++)res[i] /= A.size();
  	reverse(res.begin() + 1, res.end());
	return res;
}
vcd multiply(const vcd &A,const vcd &B){
	vcd fa(A.begin(),A.end()),fb(B.begin(),B.end());
	int da = A.size(),db = B.size(),dc = 1;

        while(dc < max(da,db))dc <<= 1;
        dc <<= 1;

	fa.resize(dc); fb.resize(dc);

	fa = fft(fa); fb = fft(fb);
	for(int i = 0; i < dc; i++) fa[i] *= fb[i];
	fa = fft_rev(fa);
	for(int i = 0; i < dc; i++) fa[i] = int(fa[i].real()+0.5);
	return fa;
	//Multiply numbers
	/*int carry = 0;
        for(int i = 0; i < dc; i++){
                C[i] += carry;
                carry = C[i]/10;
                C[i] %= 10;
        }*/

}
/* 
Example: 

in: 
4 4
1 2 3 4
1 2 3 4
out:
(1,2.55351e-15)
(4,4.20741e-15)
(10,1.84903e-15)
(20,-1.54287e-15)
(25,-2.33147e-15)
(24,-4.67438e-15)
(16,-2.07108e-15)
*/
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int s,t,k; cin >> s >> t >> k;
	string s1,s2; cin >> s1 >> s2;
	reverse(s2.begin(),s2.end());
	vector<vcd> res(4);
	forn(i,0,4){
		char c = (i == 0) ? 'A' : (i == 1) ? 'T' : (i == 2) ? 'G': 'C';
		vcd A(s1.size()),B(s2.size());
		forn(j,0,s1.size()){
			if(s1[j] == c) A[j] = 1;
			else A[j] = 0;
		}
		forn(j,0,s2.size()){
			if(s2[j] == c) B[j] = 1;
			else B[j] = 0;
		}
		res[i] = multiply(A,B);
	}
	forn(i,0,12){
		int tmp = int(res[0][i].real())+int(res[1][i].real())+int(res[2][i].real())+int(res[3][i].real());
		cout << tmp << " ";
	}
	cout << "\n";
}
