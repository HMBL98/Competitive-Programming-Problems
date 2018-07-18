#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,b) for(int i = a; i < b; i++)
#define Q 101 // prime number
#define D 256 //Number of characters in the input alphabet

void search(string txt,string pat){
	int n = txt.size();
	int m = pat.size();
	int p = 0; //hash value for pattern
	int t = 0; //hash value for text
	int h = 1;
	// The value of h would be "pow(d, M-1)%q"
	forn(i,0,m-1) h = (h*D)%Q;
	// Calculate the hash value of pattern and first
    	// window of text
	forn(i,0,m){
		p = (D*p+pat[i])%Q;
		t = (D*t+txt[i])%Q;
	}
	// Slide the pattern over text one by one
	bool status;
	vector<int> res;
	forn(i,0,n-m+1){
		// Check the hash values of current window of text
        	// and pattern. If the hash values match then only
        	// check for characters on by one
		if(p == t){
			status = true;
			forn(j,0,m)
				if(txt[i+j] != pat[j]){
					status = false;
					break;
				}
			if(status)res.push_back(i);

		}
		// Calculate hash value for next window of text: Remove
        	// leading digit, add trailing digit
		if(i < n-m){
			t = (D*(t-txt[i]*h)+txt[i+m])%Q;
			// We might get negative value of t, converting it
            		// to positive
			if(t < 0)t = (t+Q);
		}
	}
	if(!res.empty()){
		cout << res.size() << "\n";
		forn(i,0,res.size()){
			if(i)cout << " ";
			cout << res[i]+1;
		}
		cout << "\n";
	}else cout << "Not Found\n";
}
int T,caso;
int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		if(caso++) cout << "\n";
		string text,pattern;
		cin >> text >> pattern;
		search(text,pattern);
	}
}
