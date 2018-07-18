#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

typedef vector<int> vi;
int match[MAX],seen[MAX];
vector<vi> graph;

bool dfs(int u){
	if(seen[u]) return false;
	seen[u] = 1;
  	for(int i = 0; i < (int)graph[u].size(); i++){
    		int v = match[graph[u][i]];
    		if(v == -1 || dfs(v)){
      			match[graph[u][i]] = u;
      			return true;
    		}
  	}
  	return false;
}
int kuhn(int n1, int n2){
	fill(seen,seen+n1,0);
	fill(match, match + n2, -1);
  	int matches = 0;
  	for(int i = 0; i < n1; i++){
    		fill(seen,seen+n1,0);
    		if(dfs(i))matches++;
  	}
  	return matches;
}
string line;
vector<char> name;
int _size;

int main(){
	while(getline(cin,line)){
		do{
			stringstream ss(line);
			string s1,s2; ss >> s1 >> s2;
			for(int i = 0; i < s1[1]-'0'; i++){
				name.push_back(s1[0]);
				graph.push_back(vi());
				for(int j = 0; j < (int)s2.size()-1; j++){
					graph[i+_size].push_back(s2[j]-'0');
				}
			}
			_size += s1[1]-'0';
			getline(cin,line);
		}while(!line.empty());
		if(_size > 10 || kuhn(_size,10) != _size){
                	cout << "!\n";
                }else{
                	for(int i = 0; i < 10; i++){
                        	if(match[i] != -1)cout << name[match[i]];
                                else cout << "_";
                        }
                        cout << "\n";
		}
                graph.clear();
               	_size = 0;
                name.clear();
	}
}
