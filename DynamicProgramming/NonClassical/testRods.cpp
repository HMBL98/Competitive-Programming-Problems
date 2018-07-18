//10086 - Test the Rods
#include <bits/stdc++.h>
using namespace std;

int t1,t2,n,m,tmp;
vector<int> v1;
vector<int> v2;


int dp(int pos,int c1,int c2){
	if(pos >= v1.size())return 0;
	int tomar1 = 1<<20,tomar2 = 1<<20;
	if(c1+1 <= t1) tomar1 = v1[pos]+dp(pos+1,c1+1,c2);
	if(c2+1 <= t2) tomar2 = v2[pos]+dp(pos+1,c1,c2+1);
	return min(tomar1,tomar2);
}

int main(){
	while(cin >> t1 >> t2,(t1||t2)){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> m;
			for(int j = 0; j < m; j++){
				cin >> tmp;
				v1.push_back(tmp);
			}
			for(int j = 0; j < m; j++){
				cin >> tmp;
				v2.push_back(tmp);
			}
		}
		cout << dp(0,0,0) << "\n";
	}
}

