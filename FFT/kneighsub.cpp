#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
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
vcd multiply(const vcd &A,const vcd &B,int dc){
	vcd fa(A.begin(),A.end()),fb(B.begin(),B.end());
	int da = A.size(),db = B.size();

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
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k,ncase = 0;
	while(cin >> k){
		if(k == -1)break;
		string s1,s2;
		cin >> s1 >> s2;
		reverse(s2.begin(),s2.end());
		vector<vcd> res(2);

		int dc = 1;
		int maxi = max(s1.size(),s2.size());
		while(dc < maxi)dc <<= 1; 
        	dc <<= 1;

		vcd A(s1.size()); vcd B(s2.size());
		forn(i,0,2){
			char c = (i == 0) ? 'a' : 'b';
			forn(j,0,s1.size()){
				if(s1[j] == c) A[j] = 1;
				else A[j] = 0;
			}
			forn(j,0,s2.size()){
				if(s2[j] == c) B[j] = 1;
				else B[j] = 0;
			}
			res[i] = multiply(A,B,dc);
		}
		int ans = 0;
		forn(i,s2.size()-1,s1.size()){
			int tmp = int(res[0][i].real())+int(res[1][i].real());
			if(tmp <= k) ans++;
		}
		cout << "Case " << ++ncase << ": " << ans << "\n";
	}
	return 0;
}
