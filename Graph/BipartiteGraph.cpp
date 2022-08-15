#include<iostream>
#include <queue>
#include<vector> 

using namespace std;


void BFS(vector<int> g[], int numberOfEgdes, int colour[], int distance[], int parent[], int start, int bipartiColour[]){
    queue<int> q;
    q.push(start);
    
    colour[start] = 1;
    distance[start] = 0;
    parent[start] = start;
    bipartiColour[start] = 1;
    
    
    cout<<start<<" ";
    
    while(!q.empty()){
        
        int u = q.front();
        q.pop();
        
        for(int i= 0 ; i < g[u].size() ; i++){
            
            int v = g[u][i];
            if(colour[v] == 0){
                colour[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
                cout<<v<<" ";
            }
            
            
        }
        colour[u] = 2;
        
    }
}


int main(){
    
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    int colour[n]; // 0 white, 1 gray, 2 black
    int distance[n];
    int parent[n];
    int bipartiColour[n];// 1 = blue, 2 = red
    
    
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
        colour[i] = 0;
        distance[i] = -1;
        parent[i] = -1;
        bipartiColour[i] = -1;
    }
    
    
    BFS(g, numberOfEgdes, colour, distance, parent, 0, bipartiColour);
    cout<<endl;
    cout<<"parents: ";
    for(int i= 0 ; i< n ; i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    cout<<"distance: ";
    for(int i= 0 ; i< n ; i++){
        cout<<distance[i]<<" ";
    }
    
}