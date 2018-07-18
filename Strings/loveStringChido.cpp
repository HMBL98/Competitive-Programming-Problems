#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

#define MAXS 100000
#define MAXC 93
#define MAXW 10000

int g[MAXS][MAXC];
int f[MAXS];
bitset<MAXW> out[MAXS];
int query[1000+10];

void init(){
        memset(g,-1,sizeof g);
	forn(i,0,MAXS){
		f[i] = 0;
		out[i].reset();
	}
	forn(i,0,1000+10) query[i] = 0;
}
void build(vector<string> &arr){
	int state = 0,cur = 0,idx = 0;
	string str;
        ///Building a trie, each new node gets the next number as node-name.
	forn(i,0,arr.size()){
		str = arr[i];
		cur = 0;
            	for(auto &c : str){
                	idx = c - 33;
	                if(g[cur][idx] == -1){
                    		g[cur][idx] = ++state;
                	}
                	cur = g[cur][idx];
            	}
            	out[cur].set(i);
            	///stores whether i'th indexed string of arr, ends at state 'currState' or not. Thus adding the string to output by using 1 bit, hhh very memory efficient.
        }
        ///Failure function
        queue<int>q;
        int s,fail;
        forn(i,0,MAXC){
		if(g[0][i] != -1){
               		f[g[0][i]] = 0; ///here, depth is 1
                	q.push(g[0][i]);
            	}else{
                	g[0][i] = 0; ///Necessary in failure alg below, non-existing char back to state 0. To stop infinite loop at line 68.
            	}
        }
        while(!q.empty()){
        	s = q.front();
            	q.pop();
            	forn(i,0,MAXC){
                	if(g[s][i] != -1){
                    		q.push(g[s][i]);
                    		fail = f[s]; ///here is the perfect place to calculate failure of g[s][i],cuz here 'state:s' is (depth-1) state of 'state:g[s][i]'.
                    		while(g[fail][i] == -1)fail = f[fail];
                    		fail = g[fail][i];
                    		f[g[s][i]] = fail;
                    		out[g[s][i]] |= out[fail]; ///merging output of the node & it's failure node.
                    		///Read the paper of aho-corasick,published in 1975.
                	}
		}
	}
}
int nextState(int s, char ch){
        int index = ch - 33;
	///If non-existing state, use failure function to support automaton.
        while(g[s][index] == -1)s = f[s];
        return g[s][index];
}
void search(vector<string> &arr,string text){
	init();
        build(arr);
	int state = 0;
        forn(i,0,text.size()){
		state = nextState(state,text[i]); /// traverse the trie state/node for the text
            	if(out[state].count() > 0){/// if the state has at least one output
                	forn(j,0,arr.size()){//For finding position of search strings.
                    		if(out[state].test(j)){ /// if j'th string is in the output of state, means a match is found.
		                        //cout<<arr[j]<<" IS MATCHED AT POSITION: "<<i-arr[j].size()+1<<endl;
					query[j] = 1;
                    		}
                	}
            	}
        }
}
int q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	string txt; cin >> txt;
	cin >> q;
	vector<string> word(q);
	forn(i,0,q)cin >> word[i];
	search(word,txt);
	forn(i,0,q) cout << ((query[i]) ? "Y\n" : "N\n");
	return 0;
}

