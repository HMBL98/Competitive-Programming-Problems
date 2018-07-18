#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define MAX 200000+10
typedef pair<int,int> ii;
int n,k,val[MAX];
map<int,ii> mapper;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int ans1,ans2,ans3,ans4 = -1;
	forn(i,0,n){
		cin >> k;
		int sum = 0;
		forn(j,0,k){
			cin >> val[j];
			sum += val[j];
		}
		forn(j,0,k){
			if(mapper.find(sum-val[j]) == mapper.end()) mapper[sum-val[j]] = ii(i,j);
			else{
				ii act = mapper[sum-val[j]];
				if(act.first != i){
					ans1 = i; ans2 = j;
					ans3 = act.first; ans4 = act.second;
				}
			}
		}
	}
	(ans4 == -1) ? cout << "NO\n" : cout << "YES\n" << ans1+1 << " " << ans2+1 << "\n" << ans3+1 << " " << ans4+1 << "\n";
}
