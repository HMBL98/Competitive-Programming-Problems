//B. OR in Matrix
#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 110
int m,n,row[MAX],col[MAX],in[MAX][MAX],res[MAX][MAX];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	forn(i,0,m)
		forn(j,0,n){
			cin >> in[i][j];
			if(!in[i][j]){
				row[i] = 1;
				col[j] = 1;
			}
		}
	bool status = true;
	forn(i,0,m)
		forn(j,0,n){
			if(in[i][j]){
				if(row[i] && col[j]){
					status = false;
					break;
				}
				if(!row[i] && !col[j]) res[i][j] = 1;
			}
		}
	if(!status) cout << "NO\n";
	else{
		bool status2 = true;
		forn(i,0,m){
			forn(j,0,n){
				if(in[i][j]){
					bool status3 = false;
					forn(k,0,n)if(res[i][k]) status3 = true;
					forn(k,0,m)if(res[k][j]) status3 = true;
					if(!status3){status2=false;break;}
				}

			}
		}
		if(!status2) cout << "NO\n";
		else{
			cout << "YES\n";
			forn(i,0,m){
				forn(j,0,n) cout << res[i][j] << " ";
				cout << "\n";
			}
		}
	}
}
