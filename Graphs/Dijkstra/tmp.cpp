#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a = {1,5,7,8,8,9,10,11,20,25,98};
	sort(a.begin(),a.end());
	for(auto &x: a)cout << x << " ";
	cout << "\n";
	int tmp;
	while(cin >> tmp){
		auto l = lower_bound(a.begin(),a.end(),tmp);
		cout << (l-a.begin()) << "\n";
	}
}
