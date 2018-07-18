#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define INF 1000000000
#define MAX 100

int graph[MAX][MAX],p[MAX][MAX],V,E;

void printP(int i,int j){
	if(i != j) printP(i,p[i][j]);
	cout << " " << j;
}
int main(){
	cin >> V >> E;
	forn(i,0,V){
		forn(j,0,V){
			graph[i][j] = INF;
			p[i][j] = i;
		}
		graph[i][i] = 0;
	}
	while(E--){
		int u,v,c; cin >> u >> v >> c;
		graph[u][v] = c; //dirigido
	}
	forn(k,0,V)
		forn(i,0,V)
			forn(j,0,V)
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k]+graph[k][j];
					p[i][j] = p[k][j];
				}
	int src, dst; cin >> src >> dst;
	cout << graph[src][dst] << "\n";
	printP(src,dst);
	cout << "\n"; 
}
