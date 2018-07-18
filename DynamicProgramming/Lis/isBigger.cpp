#include <bits/stdc++.h>
using namespace std;
int size,iq;
struct info{
	int s,iq;
	int index;
};
bool menor(info a,info b){
	return a.iq > b.iq;
}
vector<info> valores;
int lis[1000+10];

int main(){
	int i = 1;
	while(scanf("%d %d",&size,&iq) != EOF){
		info tmp; tmp.s = size; tmp.iq = iq; tmp.index = i++;
		valores.push_back(tmp);
	}
	sort(valores.begin(),valores.end(),menor);
	lis[0] = 1;
	int mayor = 1;
	int indice;
	int recorrido[valores.size()+10];
	memset(recorrido,-1,sizeof recorrido);
	for(int i = 1; i < valores.size(); i++){
		for(int j = 0; j < i; j++){
			if(valores[j].s < valores[i].s){
				if(lis[j] > lis[i]){
					lis[i] = lis[j];
					recorrido[i] = j;
				}
			}
		}
		lis[i]++;
		if(lis[i] > mayor){
			mayor = lis[i];
			indice = i;
		}
	}
	printf("%d\n",mayor);
	vector<int> indices;indices.push_back(valores[indice].index);
	int anterior = recorrido[indice];
	while(anterior != -1){
		indices.push_back(valores[anterior].index);
		anterior = recorrido[anterior];
	}
	reverse(indices.begin(),indices.end());
	for(int a : indices)
		printf("%d\n",a);
}
