#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef complex<double> cd;
typedef vector<cd> vcd;

void fft(vcd &A){
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
    		double alpha = 2 * M_PI * i / n;
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
  	A = cur;
}
void fft_rev(vcd &A){
	int n = A.size();
	fft(A);
  	for(int i = 0; i < (int)A.size(); i++)A[i] /= n;
  	reverse(A.begin() + 1, A.end());
}
void multiply(const vcd &A,const vcd &B,vector<int> &C){
	vcd fa(A.begin(),A.end()),fb(B.begin(),B.end());
	int da = A.size(),db = B.size(),dc = 1;

        while(dc < max(da,db))dc <<= 1;
        dc <<= 1;

	fa.resize(dc); fb.resize(dc); C.resize(dc);

	fft(fa); fft(fb);
	for(int i = 0; i < dc; i++) fa[i] *= fb[i];
	fft_rev(fa);
	for(int i = 0; i < dc; i++) C[i] = int(fa[i].real()+0.5);

	//Multiply numbers
	/*int carry = 0;
        for(int i = 0; i < dc; i++){
                C[i] += carry;
                carry = C[i]/10;
                C[i] %= 10;
        }*/

}
int N,M;
int main(){
	optimizar_io;
	while(cin >> N){
		vector<int> pots;
		int degree = -1;
		for(int i = 0; i < N; i++){
			int tmp; cin >> tmp;
			degree = max(degree,tmp);
			pots.push_back(tmp);
		}
		vcd A(degree+1);
                vcd B(degree+1);
                A[0] = 1;
                B[0] = 1;
		for(int i = 0; i < N; i++) A[pots[i]] = B[pots[i]] = 1;
		vector<int> C;
		multiply(A,B,C);
		//for(int i = 0; i < C.size(); i++) cout << i <<  " " << C[i] << "\n";
		int res = 0;
		cin >> M;
		for(int i = 0; i < M; i++){
			int tmp; cin >> tmp;
			if(tmp < C.size() && C[tmp]){
				//cout << tmp << "\n";
				res++;
			}
		}
		cout << res << "\n";
	}
}
