#include <iostream>
#define INF 2000 * 100001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
        int a, n, m; cin >> a >> n >> m;
            bool rain[a]; int umb[a], dp[a + 1];
                dp[a] = INF;
                    for (int i = 0; i < a; i++) {
                            rain[i] = false;
                                    umb[i] = 100001;
                                            dp[i] = INF;
                                                }
                                                    for (int i = 0; i < n; i++) {
                                                            int l, r; cin >> l >> r;
                                                                    for (int j = l; j < r; j++) rain[j] = true;
                                                                        }
                                                                            for (int i = 0; i < m; i++) {
                                                                                    int x, p; cin >> x >> p;
                                                                                            umb[x] = min(umb[x], p);
                                                                                                }
                                                                                                    dp[0] = 0;
                                                                                                        for (int i = 1; i <= a; i++) {
                                                                                                                if (rain[i - 1]) {
                                                                                                                            for (int j = 0; j < i; j++) {
                                                                                                                                            if (umb[j] != 100001) dp[i] = min(dp[i], dp[j] + (i - j) * umb[j]);
                                                                                                                                                        }
                                                                                                                                                                } else dp[i] = dp[i - 1];
                                                                                                                                                                    }
                                                                                                                                                                        cout << (dp[a] == INF ? -1 : dp[a]) << endl;
                                                                                                                                                                            return 0;
                                                                                                                                                                            }
