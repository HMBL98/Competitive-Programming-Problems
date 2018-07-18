#include <bits/stdc++.h>

#define faster_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define file_name(a) (freopen(((string)(a) + ".in").c_str(),"r",stdin), freopen(((string)(a) + ".out").c_str(),"w",stdout))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define all(a) a.begin(), a.end()
#define clr(a,b) memset((a), (b), sizeof(a))
#define getmax(a,b) ((a) > (b) ? (a) : (b))
#define getmin(a,b) ((a) < (b) ? (a) : (b))
#define getmodule(a) ((a) < 0 ? (-a) : (a))
#define pi acos(-1)
#define st first
#define nd second
#define pb push_back
#define mp make_pair

#define MX (int)(3e5+10)
#define MOD (int)(1e9+7)
#define MAXN (1 << 8)
#define MAXX 212422

#define left_node (cur_node << 1)
#define right_node (left_node | 1)
#define mid ((left + right) >> 1)
#define bit(x,y) ((x >> y) & 1)


using namespace std;

const int INF = 1e9 + 143;
const long long LINF = 1e18 + 143;

typedef unsigned long long ull;
typedef int ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef vector <ll> vl;
typedef vector <pll> vll;
typedef vector <vl> vvl;




namespace Main {

      struct line {

            ld dy, dx;

            line() {}
            line( ld _m, ld _n ) {

                  dy = _m;
                  dx = _n;

            }

            ld get( ld x ) {

                  return ( dy * x + dx );

            }

      };

      ll len;
      line st[MAXX];

      inline ld inter( line l1, line l2 ) {

            return ( l2.dx - l1.dx ) / ( l1.dy - l2.dy );

      }

      inline ll ok( line l1, line l2, line l3 ) {

            return inter( l1, l3 ) < inter( l1, l2 );

      }

      inline void push( line temp ) {

            while ( len >= 2 && ok( st[len - 1], st[len], temp ) ) {

                  len--;

            }

            st[++len] = temp;

      }

      inline ld query( ld x ) {

            if ( len == 0 ) {

                  return LINF;

            }

            ll left = 0, right = len;

            while ( left + 1 < right ) {

                  if ( x < inter( st[mid], st[mid + 1] ) ) {

                        right = mid;

                  } else {

                        left = mid;

                  }

            }

            return st[right].get( x );

      }

      inline ll next() {

            ll x;
            cin >> x;

            return x;

      }

      ll a[MAXX];
      ld ans[MAXX], nf[MAXX], s[MAXX], p[MAXX], q[MAXX];

      inline void run() {

            ll n = next();
            ll k = next();

            rep(i, 1, n) {

                  a[i] = next();

            }

            rep(i, 1, n) {

                  s[i] = s[i - 1] + a[i];
                  p[i] = p[i - 1] + s[i] / double( a[i] );
                  q[i] = q[i - 1] + 1.0 / double( a[i] );

            }

            ans[0] = 0;

            rep(i, 1, n) {

                  ans[i] = LINF;

            }

            rep(x, 1, k) {

                  len = 0;
                  rep(i, 0, n) {

                        nf[i] = query( q[i] ) + p[i];

                        if ( nf[i] > LINF ) {

                              nf[i] = LINF;

                        }

                        ld aa = -s[i];
                        ld bb = q[i] * s[i] - p[i] + ans[i];

                        push( line( aa, bb ) );

                  }

                  rep(i, 0, n) {

                        ans[i] = nf[i];

                  }

            }

            printf("%.10f\n", double(ans[n]));

            cerr << "\n\nElapsed time is: " << clock() / CLOCKS_PER_SEC << "\n\n";

      }


};



int main() {

      faster_io;

      Main::run();

      return 0;

}
