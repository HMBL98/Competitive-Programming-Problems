#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <complex>

#include <time.h>
#pragma comment(linker, "/STACK:20000000")

#define fr(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define fd(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

int ri(){int x;scanf("%d",&x);return x;}
ll rll(){ll x;scanf("%lld",&x);return x;}

typedef complex<double> base;
const double PI = acos(-1.0);
vector<int> order;

void fft (vector<base> &a,bool invert) 
{
	int n = a.size();
	for(int i = 0;i < n;i++)
		if (order[i] < i)
			swap(a[i],a[order[i]]);
	for (int len = 2; len <= n; len <<= 1)
	{
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		int half = len >> 1;
		vector<base> w(half);
		base w0(1);
		for(int i = 0;i < half;i++)
			w[i] = w0,w0 *= wlen;
		for (int i = 0; i < n; i += len) 
		{
			for (int j = 0; j < half; j++) 
			{
				base u = a[i + j];
				base v = a[i + j + half] * w[j];
				a[i + j] = u + v;
				a[i + j + half] = u - v;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; i++)
			a[i] /= n;
}

void precalc(int n,int L)
{
	order.resize(n);
	for(int i = 0;i < n;i++)
	{
		int res = 0;
		for(int j = 0;j < L;j++)
			if (i & (1<<j))
				res |= 1<<(L - j - 1);
		order[i] = res;
	}
}

vector<int> fft_mul(vector<int> a,vector<int> b)
{
	vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
	int n = 1;
	int L = 0;
	while(a.size() + b.size() > n)
		n <<= 1,L++;
	fa.resize(n);
	fb.resize(n);
	precalc(n,L);
	fft(fa,false);
	fft(fb,false);
	for(int i = 0;i < n;i++)
		fa[i] *= fb[i];
	fft(fa,true);

	vector<int> res(n);
	for(int i = 0;i < n;i++)
	{
		res[i] = (int)(fa[i].real() + 0.5);
		res[i] = min(res[i],1);
	}
	while(res.back() == 0 && res.size() > 1)
		res.pop_back();
	return res;
}

int wtf[10050];

void solve()
{
	int n = ri(),m = ri();
	if (m == 0)
	{
		cout << 1 << endl;
		return;
	}
	vector<int> y;
	for(int i = 1;i <= n;i++)
		wtf[ri()] = 1;
	for(int i = 0;i <= 1000;i++)
	    y.pb(wtf[i]);
	vector<int> z (1,1);
	while(m)
	{
		if (m & 1)
			z = fft_mul(z,y);
		y = fft_mul(y,y);
		m >>= 1;
	}
	for(int i = 0;i < z.size();i++)
	    if (z[i])
		    printf("%d ",i);
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("C:/Users/CleRIC/Desktop/������/acm.timus.ru/input.txt","rt",stdin);
		freopen("C:/Users/CleRIC/Desktop/������/acm.timus.ru/output.txt","wt",stdout);
	#else
		//freopen("input.in","rt",stdin);
		//freopen("output.out","wt",stdout);
	#endif*/

	solve();

/*	#ifndef ONLINE_JUDGE
		printf("\n\ntime-%.3lf",clock()*1e-3);
	#endif*/

	return 0;
}
