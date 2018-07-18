#include <bits/stdc++.h>
using namespace std;
#define MAXN 100100

int BIT[MAXN];
unsigned long long int N, ordered;

int query(int idx){
	int ans = 0;
	for (; idx; idx -= idx&-idx)
		ans += BIT[idx];
	return ans;
}

int update(int idx, int diff){
	for (; idx < MAXN; idx += idx&-idx)
		BIT[idx] += diff;
}

int main(void){
	int i, a;
	cin >> N;
	for (i = 0; i < N; i++){
		cin >> a;
		ordered += query(a);
		update(a+1, 1);
	}
	cout << N*(N-1)/2 - ordered << endl;

	return 0;
}
