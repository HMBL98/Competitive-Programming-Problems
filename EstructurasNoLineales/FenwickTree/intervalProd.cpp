#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
	private:
  		vi ft;
	public:
  		FenwickTree() {}
  		// initialization: n + 1 zeroes, ignore index 0
  		FenwickTree(int n) { ft.assign(n + 1, 0); }
  		int rsq(int b) {                                     // returns RSQ(1, b)
			int sum = 0;
			for (; b; b -= LSOne(b)) sum += ft[b];
    			return sum;
		}
  		int rsq(int a, int b) {                              // returns RSQ(a, b)
    			return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
		}
  		// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  		void adjust(int k, int v) {                    // note: n = ft.size() - 1
    			for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
		}
};
int main(){
	optimizar_io;
	int n,k;
	vector<int> array;
	while(cin >> n >> k){
		array.assign(n+1,0);
		FenwickTree ceros(n+1),negativos(n+1);
		for(int i = 1; i <= n; i++){
			cin >> array[i];
			if(array[i] < 0){
				negativos.adjust(i,1);
			}
			if(array[i] == 0){
				ceros.adjust(i,1);
			}
		}
		string ans = "";
		for(int i = 0; i < k; i++){
			char c; int a,b;
			cin >> c;
			if(c == 'C'){
				cin >> a >> b;
				if(array[a] == 0){
					if(b < 0){
						ceros.adjust(a,-1);
						negativos.adjust(a,1);
					}else if(b > 0){
						ceros.adjust(a,-1);
					}else{
						//ceros.adjust(a,1);
					}
				}else if(array[a] < 0){
					if(b < 0){
                                                //negativos.adjust(a,1);
                                        }else if(b > 0){
						negativos.adjust(a,-1);
                                        }else{
						negativos.adjust(a,-1);
                                                ceros.adjust(a,1);
                                        }
				}else{
					if(b < 0){
                                                negativos.adjust(a,1);
                                        }
					if(b == 0){
						ceros.adjust(a,1);
					}
				}
				array[a] = b;
			}else{
				cin >> a >> b;
				int ce = ceros.rsq(a,b);
				int nega = negativos.rsq(a,b);
				/*cout << "negativos " << nega << endl;
				cout << "ceros " << ce << endl;*/
				if(ce > 0){
					ans += '0';
				}else{
					if(nega%2 == 0){
						ans += '+';
					}else{
						ans += '-';
					}
				}
			}
		}
		cout << ans << endl;
	}
}
