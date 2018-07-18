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

#define MAX 1500+10
int size,counter,nodes;
int mat[MAX][MAX];
ll k;

void gene(int n){
	if(n == 0){
		//cout << 1 << " " << counter << "\n";
		mat[1][counter] = 1;
		mat[counter][1] = 1;
		forn(i,0,size-1){
			//cout << counter << " " << counter+1 << "\n";
			mat[counter][counter+1] = 1;
			mat[counter+1][counter] = 1;
			counter++;
		}
		//cout << counter <<" " << 2 << "\n";
		nodes = max(nodes,counter);
		mat[counter][2] = 1;
		mat[2][counter] = 1;
	}else if(n == 1){
		//cout << 1 << " " << counter << "\n";
		mat[1][counter] = 1;
		mat[counter][1] = 1;
               	//cout << 1 << " " << counter+size << "\n";
		mat[1][counter+size] = 1;
		mat[counter+size][1] = 1;
               	forn(i,0,size-1){
                       	//cout << counter << " " << counter+1 << "\n";
			mat[counter][counter+1] = 1;
			mat[counter+1][counter] = 1;
                       	//cout << counter+size << " "<< counter+size+1 << "\n";
			mat[counter+size][counter+size+1] = 1;
			mat[counter+size+1][counter+size] = 1;
                       	counter++;
               	}
		//cout << counter << " " << 2 << "\n",
		mat[counter][2] = 1;
		mat[2][counter] = 1;
		//cout << counter+size << " " << 2 << "\n";
		mat[counter+size][2] = 1;
		mat[2][counter+size] = 1;
		nodes = max(nodes,counter+size);
	}else{
		//cout << 1 << " " << counter << "\n";
		mat[1][counter] = 1;
		mat[counter][1] = 1;
		//cout << 1 << " " << counter+size << "\n";
                mat[1][counter+size] = 1;
		mat[counter+size][1] = 1;

		forn(i,0,n-1){
			//cout << counter << " " << counter+1 << "\n";
			mat[counter][counter+1] = 1;
			mat[counter+1][counter] = 1;	
			//cout << counter+size << " " << counter+size+1 << "\n";
                       	mat[counter+size][counter+size+1] = 1;
			mat[counter+size+1][counter+size] = 1;
			//cout << counter << " " << counter+size+1 << "\n";
			mat[counter][counter+size+1] = 1;
			mat[counter+size+1][counter] = 1;
			//cout << counter+size << " " << counter+1 << "\n";
                        mat[counter+size][counter+1] = 1;
			mat[counter+1][counter+size] = 1;
			counter++;
		}
		if(n < size){
			forn(i,0,size-n){
				//cout << counter << " " << counter+1 << "\n";
				mat[counter][counter+1] = 1;
				mat[counter+1][counter] = 1;
				//cout << counter+size << " " << counter+size+1 << "\n";
                               	mat[counter+size][counter+size+1] = 1;
				mat[counter+size+1][counter+size] = 1;
				counter++;
			}
		}
		//cout << counter << " " << 2 << "\n";
		mat[counter][2] = 1;
		mat[2][counter] = 1;
		//cout << counter+size << " " << 2 << "\n";
                mat[counter+size][2] = 1;
		mat[2][counter+size] = 1;
		nodes = max(nodes,counter+size);
	}
	counter += size+1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;

	/*if(k == 1){
		cout << 2 << "\n";
		cout << "NY\nYN\n";
		return 0;
	}*/
	size = -1;
	counter = 3;

	forr(i,30,0){
		if(k&(1ll<<i)){
			cout << 1;
			if(size == -1)size = i;
			//gene(i);
		}else cout << 0;
	}
	cout << "\n";
	cout << nodes << "\n";
	forn(i,1,nodes+1){
		forn(j,1,nodes+1)
			if(mat[i][j])cout << "Y";
			else cout << "N";
		cout << "\n";
	}
}

