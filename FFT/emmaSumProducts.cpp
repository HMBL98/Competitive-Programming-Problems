#include <bits/stdc++.h>
using namespace std;

#define mod 100003
typedef complex<double> cd;
typedef vector<cd> vcd;
typedef long long ll;

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
void multiply(vcd &A,const vcd &B){
	vcd fa(A.begin(),A.end()),fb(B.begin(),B.end());
	int da = A.size(),db = B.size(),dc = 1;

        while(dc < max(da,db))dc <<= 1;
        dc <<= 1;

	fa.resize(dc); fb.resize(dc);
	fft(fa); fft(fb);
	for(int i = 0; i < dc; i++) fa[i] *= fb[i];
	fft_rev(fa);
	for(int i = 0; i < dc; i++){
		fa[i] = ll(fa[i].real()+0.5)%mod;
	}
	A = fa;

	//Multiply numbers
	/*int carry = 0;
        for(int i = 0; i < dc; i++){
                C[i] += carry;
                carry = C[i]/10;
                C[i] %= 10;
        }*/

}
int N,Q;

int main(){
	cin >> N;
	vector<vcd> polis(N);
	for(int i = 0; i < N; i++){
		int tmp; cin >> tmp;
		vcd tmp1(2);
		tmp1[0] = tmp;
		tmp1[1] = 1;
		polis[i] = tmp1;
	}
	int i = 0,k = 0;
	int pos1,pos2;
	while(1){
		i = 0;
		pos1 = 1<<(k+1); pos1 *= i;
		pos2 = 1<<k; pos2 *= (2*i+1);
		if(pos1 >= polis.size() || pos2 >= polis.size())break;
		while(1){
			//cout << pos1 << " " << pos2 << "\n";
			if(pos1 >= polis.size() || pos2 >= polis.size())break;
			multiply(polis[pos1],polis[pos2]);
			i++;
			pos1 = 1<<(k+1); pos1 *= i;
	                pos2 = 1<<k; pos2 *= (2*i+1);
		}
		k++;
	}
	cin >> Q;
	while(Q--){
		int q; cin >> q;
		cout << polis[0][N-q].real() << "\n";
	}
	//for(int i = 0; i < polis[0].size(); i++) cout << polis[0][i] << "\n";
}
