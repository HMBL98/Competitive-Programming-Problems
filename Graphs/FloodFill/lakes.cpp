#include <bits/stdc++.h>
using namespace std;

int m; string y,x;
vector<string> grid;

int movX[] = {-1,0,0,1};
int movY[] = {0,-1,1,0};

bool mover(int i,int j){
	if(i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == 'V' || grid[i][j] == '1') return false;
	return 1;
}

int dfs(int i,int j){
	grid[i][j] = 'V';
	int res = 1;
	for(int k = 0; k < 4; k++){
		if(mover(i+movY[k],j+movX[k])) res += dfs(i+movY[k],j+movX[k]);
	}
	return res;
}

int main(){
	cin >> m;
	int caso = 0;
	while(m--){
		if(caso++) cout << "\n";
		cin >> y >> x;
		cin.clear();cin.ignore();
		string tmp;
		while(getline(cin,tmp)){
			if(tmp.empty())break;
			grid.push_back(tmp);
		}
		int res = dfs(stoi(y)-1,stoi(x)-1);
		//for(int i = 0; i < grid.size(); i++) cout << grid[i] << "\n";
		cout << res << "\n";
		grid.clear();
	}
}
