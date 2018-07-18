#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
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
void exp(vcd & A,int k){
	vcd B(A.begin(),A.end());
	A = vcd(B.size());
	A[0] = 1;
	while(k){
		A.resize(A.size()*2,0);
		B.resize(B.size()*2,0);
		B = fft(B);
		if(k&1){
			A = fft(A);
			for(int i = 0; i < A.size(); i++) A[i] *= B[i];
			A = fft_rev(A);
			for(int i = 0; i < A.size(); i++)
                		if(ll(A[i].real()+0.5))A[i] = 1;
                		else A[i] = 0;
		}
		for(int i = 0; i < B.size(); i++)B[i] *= B[i];
        	B = fft_rev(B);
        	for(int i = 0; i < B.size(); i++)
            		if(ll(B[i].real()+.5)) B[i] = 1;
            		else B[i] = 0;

		k >>= 1;
	}
}
int n,k;
int main(){
	optimizar_io;
	cin >> n >> k;
	vcd A(1024);
	for(int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		A[tmp] = 1;
	}
	exp(A,k);
	for(int i = 0; i < A.size(); i++) if(A[i].real() == 1) cout << i << " ";
	//cout << "\n";
}
