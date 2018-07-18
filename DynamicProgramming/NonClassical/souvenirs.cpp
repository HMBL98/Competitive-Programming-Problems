#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 100+10,MX2 = MX*MX*10;
int t[MX],s[MX],p[MX];
int g,c,n,dp[2][MX][MX2];

inline int rod(int a, int b){
	return (2 * a + b) / (2*b);
}

#define techo(a,b) (((a) + (b) - 1) / (b))

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> g >> c >> n;

	forn(i,0,n){
		string str;
		cin >> str >> p[i] >> s[i];
		if(str[i] == 'h')t[i] = 0;
		else if(str[i] == 'e')t[i] = 1;
		else t[i] = 2;
	}
	for (int i = n - 1; i >= 0; i--) {
        	int x = i % 2, y = 1 - x;
        	for (int j = 0; j <= c; j++) {
            		for (int k = 0; k <= 2 * (i + 1) * MX; k++ ) {
                		dp[x][j][k] = dp[y][j][k];
                		int &res = dp[x][j][k];
                		if (!t[i]) {
                    			int d = k + rod(g - s[i], p[i]) * p[i];
                    			if (k >= s[i]) res = max(res, 1 + dp[y][j][k-s[i]]);
                    			if (j && d < MX2) res = max(res, 1 + dp[y][j-1][d]);
		                } else if (t[i] == 1) {
                		    int d = k + techo(g - s[i], p[i]) * p[i];
		                    if (k >= s[i]) res = max(res, 1 + dp[y][j][k-s[i]]);
                		    else if (j && d < MX2) res = max(res, 1 + dp[y][j-1][d]);
		                } else {
                		    int d = k + ((g - s[i]) / p[i]) * p[i];
		                    if (k >= s[i]) res = max(res, 1 + dp[y][j][k-s[i]]);
                		    if (j && d < MX2) res = max(res, 1 + dp[y][j-1][d]);
                		}
            		}
        	}
    	}
    	cout << dp[0][c][0] << "\n";
    	return 0;
}
