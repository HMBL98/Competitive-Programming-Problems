#include <bits/stdc++.h>
using namespace std;
int n,n2,m;
struct tower{
	int num;
	int can;
};
struct areaCom{
	int cuantos;
	vector<int> to;
};
vector<tower> torres;
vector<areaCom> areas;

void backtrack(vector<tower> t,int pos){
	if(t.size() == 3){
		for(int i = 0; i < t.size(); i++){
			cout << t[i].can <<  " ";
		}
		cout << endl;
		return;
	}else{
		vector<tower> tmp;
		for(int i = pos; i < torres.size(); i++){
			tmp = t;
			tmp.push_back(torres[i]);
			backtrack(tmp,i+1);
		}
	}
}
int main(){
	cin >> n >> n2;
	for(int i = 1; i <= n; i++){
		tower tmp;
		tmp.num = i;
		cin >> tmp.can;
		torres.push_back(tmp);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int t;
		areaCom tmp;
		cin >> t;
		for(int j = 0; j < t; j++){
			int num;
			cin >> num;
			tmp.to.push_back(num);
		}
		cin >> tmp.cuantos;
		areas.push_back(tmp);
	}
	vector<tower> asd;
	backtrack(asd,0);
}
