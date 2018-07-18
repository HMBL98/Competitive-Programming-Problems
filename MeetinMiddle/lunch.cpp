#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
#define MAX 5000+10
ll l,s,m,d,b,sA[MAX],mA[MAX],dA[MAX],bA[MAX],res;
vector<ll> usados1,usados2;

int main(){
	optimizar_io;
	while(cin >> l >> s >> m >> d >> b,(l||s||m||d||b)){
		res = 0;
		for(int i = 0; i < s; i++) cin >> sA[i];
		for(int i = 0; i < m; i++) cin >> mA[i];
	        for(int i = 0; i < d; i++) cin >> dA[i];
                for(int i = 0; i < b; i++) cin >> bA[i];

		for(int i = 0; i < s; i++)for(int j = 0; j < m; j++) if(sA[i]+mA[j] < l) usados1.push_back(sA[i]+mA[j]);
		for(int i = 0; i < d; i++)for(int j = 0; j < b; j++) if(dA[i]+bA[j] < l) usados2.push_back(dA[i]+bA[j]);

		sort(usados2.begin(),usados2.end());
		for(int i = 0; i < usados1.size(); i++){
			ll ini = 0, fin = usados2.size();
			while(ini < fin){
				ll mitad = (ini+fin)>>1;
				if(usados1[i]+usados2[mitad] <= l) ini = mitad+1;
				else fin = mitad;
			}
			res += ini;
		}
		cout << res << "\n";
		usados1.clear(); usados2.clear();

	}
}
