#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define MAX 1000000+10

int l[MAX],c[MAX];
vector<int> st;
string line;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> line;
	forn(i,0,line.size()) l[i] = c[i] = -1;
	int maxi = -1,counter = 0;
	forn(i,0,line.size()){
		if(line[i] == '(') st.push_back(i);
		else{
			if(!st.empty()){
				c[i] = st.back(); st.pop_back();
				l[i] = (l[c[i]-1] != -1) ? l[c[i]-1] : c[i];
				maxi = max(maxi,i-l[i]+1);
			}
		}
	}
	forn(i,0,line.size()){
		if(l[i] >= 0 && i-l[i]+1 == maxi)counter++;
		//cout << i << " " << c[i] <<  " " << l[i] << "\n";
	}
	if(maxi == -1) maxi = 0,counter = 1;
	cout << maxi << " " << counter << "\n";
}


