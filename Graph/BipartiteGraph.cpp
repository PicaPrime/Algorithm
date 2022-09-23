#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;


bool isBipartite(vector<int> g[], int src, int colour[]){
	queue<int> q;
	q.push(src);
	colour[src] = 1;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i=0 ; i< g[u].size() ; i++){
			int v = g[u][i];
			
			if(colour[v] == -1){
				if(colour[u] == 1){
					colour[v] = 2;
				}
				else{
					colour[v] = 1;
				}
				q.push(v);
			}
			if(colour[v] == colour[u]){
				cout<<"not a bipartite graph"<<endl;
				return false;
			}
		}
	}
	return true;
}

int main(){
    
	int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    int colour[n]; // 1 gray, 2 black
    //int distance[n];
    //int parent[n];
    
    
    vector<int> g[n];
    int numberOfEgdes;
    cout<<"enter the numberOfEgdes: ";
    cin>>numberOfEgdes;
    
    for(int i=0 ; i< numberOfEgdes ; i++){
        int u , v;
        cin>>u>>v;
        g[v].push_back(u);
        g[u].push_back(v);
    }


	for(int i=0 ; i< n ; i++){
		colour[i] = -1;
	}

	if(isBipartite(g, 0, colour)){
		cout<<"yes"<<endl;
	}

	for(int i=0 ; i< n ; i++){
		cout<<colour[i]<<" ";
	}

	return 0;
}
