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

	for(int i = 0; i < A.size(); i++) A[i] = int(A[i].real()+0.5);
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
	int da,db;
	cin >> da >> db;
	vc A(da),B(db);

	for(int i = 0; i < da; i++) cin >> A[i];
	for(int i = 0; i < db; i++) cin >> B[i];

	vc C = multiply(A,B);
	for(int i = 0; i < C.size(); i++) cout << C[i] << "\n";
	return 0;
}
