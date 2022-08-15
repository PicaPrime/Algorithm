#include<iostream>
#include<vector>
using namespace std;

    int colour[100]; // 0 white, 1 gray, 2 black
    int parent[100];
    int discoverT[100];
    int finishT[100];
    int time = 0;


void visit(int u, vector<int> g[]){

    colour[u] = 1; // 1 or gray means, right now now we are in this vertix
    time++;
    discoverT[u] = time; // initializing discover time  

    cout<<u<<" ";

    for(int i=0 ; i< g[u].size(); i++){
        if(colour[g[u][i]] == 0){
            parent[g[u][i]] = u;
            visit(g[u][i], g);
        }
    }

    colour[u] = 2;
    time++;
    finishT[u] = time;

}

void DFS(vector<int> g[], int n){

    for(int i=0 ; i< n ; i++){
        if(colour[i] == 0){
            visit(i, g);;
        }
    }

}



int main(int argc, char const *argv[]){
    
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    
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
        parent[i] = -1;
        discoverT[i] = -1;
        finishT[i] = -1;
        discoverT[i] = -1;
    }

    DFS(g, n);

    return 0;
}
