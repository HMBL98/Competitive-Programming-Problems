#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000000
typedef long double ld;
typedef complex<ld> cld;
typedef vector<cld> vc;

const ld PI = acos(-1.0);

cld wpw[MAXN];
int rev[MAXN];

void fft(vc &a,int n,bool invert){
	for(int i = 0; i < n; i++)if(i < rev[i])swap(a[i],a[rev[i]]);
	for(int len = 2; len <= n; len <<= 1){
		ld ang = 2.0L * PI / len * (invert ? -1.0L : + 1.0L);
		int len2 = len >> 1 ;

		cld wl(cos(ang),sin(ang));
		wpw[0] = cld(1,0);
		for(int i = 1; i < len2; i++)wpw[i] = wpw[i-1]*wl;

		cld t; int r, l;
		for(int i = 0; i < n; i += len){
			for(int j = 0; j < len/2; j++){
				r = i+j+len/2; l = i+j;
				t = a[r]*wpw[j];
				a[r] = a[l] - t;
				a[l] += t;
			}
		}
	}
	if(invert)for(int i = 0; i < n; i++)a[i] /= n;
}
void calcRev(int n,int ln) {
	for(int i = 0; i < n; i++){
		rev[i] = 0;
		for(int j = 0; j < ln; j++)
			if(i&(1 << j))
				rev[i] |= 1 << (ln-1-j);
	}
}
vc multiply(vc A, vc B){
	int n = 1,logn = 0;
	while(n < max(A.size(),B.size())) n <<= 1, logn++;
	n <<= 1,logn++;

	A.resize(n); B.resize(n);
	calcRev(n,logn);

	fft(A,A.size(),false);
	fft(B,B.size(),false);
	for(int i = 0; i < A.size(); i++) A[i] *= B[i];
	fft(A, A.size(), true);
	for(int i = 0; i < A.size(); i++){
		int tmp =  int(A[i].real()+0.5);
		if(tmp) A[i] = 1;
		else A[i] = 0;
	}
	while(int(A.back().real()) == 0 && A.size() > 1) A.pop_back();
	return A;

        /*Multiply numbers
	int carry = 0;
        for(int i = 0; i < n; i++){
		int digit = int(A[i].real()+0.5)
                digit += carry;
                carry = digit/10;
                digit %= 10;
        }*/
}
vc exp(vc A,int b){
        vc res = {1};
        while(b){
                if(b&1)res = multiply(res,A);
                b >>= 1;
                A = multiply(A,A);
        }
        return res;
}
int n,k;
int main(){
        cin >> n >> k;
        vc A(1024);
        for(int i = 0; i < n; i++){
                int tmp; cin >> tmp;
                A[tmp] = 1;
        }
        vc ans = exp(A,k);
        for(int i = 0; i < ans.size(); i++) if(int(ans[i].real())) cout << i << " ";
        cout << "\n";
}

