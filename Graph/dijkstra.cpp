#include<stdio.h>
#include<vector>
#include <bits/stdc++.h>

using namespace std ;

struct node{
    int nd;
    int weight ;
};

struct myqueue{
    int name;
    int key ;
    bool flag ;
};

vector<node> g[100] ; // adj list for storing the graph
struct myqueue Q[100];
int numOfNodes ; // number of vertices
int numOfEdges ; // number of edges 
int dis[100] ; // for storing the distance from souce node to all individual nodes
int  par[100] ; // for storing parent node of an indivual node

int pop(){ 
    
    // returns poped element and deletes that element
    int min = INT_MAX ;
    int index ;
    for(int i = 0 ; i < numOfNodes ; i++){

        if(Q[i].key < min && Q[i].flag == true){
            min = Q[i].key ;
            index = i ;
        }
    }
    Q[index].flag = false ;
    return Q[index].name ;
}

bool isEmpty(){
    // returns ture if the queue is empty
    for(int i = 0 ; i < numOfNodes ; i++){
        if(Q[i].flag)
                return false ;
    }
    return true ;
}



void Dijkstra(){

    while(!isEmpty()){
        int u = pop() ;
        for(int i = 0 ; i < g[u].size() ; i++){
            node t = g[u][i] ;
            int v = t.nd ;
            int w = t.weight ;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w ;
                par[v] = u ;
                Q[v].key = dis[v] ;
            }
        }
    }

}


void printPath_withCost(int src, int destination, int constant, vector<int> path){

    if(src == destination){
        path.push_back(destination);
        for(int i= path.size()-1 ; i>= 0 ; i--){
            cout<<path[i]<<" ";
        }
        cout<<" cost: "<<dis[constant]<<endl;
        return;
    }

    path.push_back(destination);

    return printPath_withCost(src, par[destination], constant, path);

}
int main(){
    
    cout<<"enter the number of nodes: ";
    cin>>numOfNodes;
    cout<<"enter the number of edges in the graph: ";
    cin>>numOfEdges;

    cout<<"enter the edges with their costs "<<endl;
    cout<<"input format : vertics vertics cost"<<endl;

    for(int i = 0 ; i < numOfEdges ; i++){ // this loop takes input 
        int u, v, w;
        cin>>u>>v>>w;
        struct node temp;
        temp.nd = v ;
        temp.weight = w ;
        g[u].push_back(temp) ;
        temp.nd = u ;
        g[v].push_back(temp) ;
    }

    for(int k = 0 ; k < numOfNodes ; k++){ // every k is a source vertics 

        cout<<"For source vertics : "<<k;
        for(int i = 0 ; i < numOfNodes ; i++)
        {
            dis[i] = INT_MAX ;
            par[i] = -1 ;
        }
        int src = k ;
        dis[src] = 0 ;
        for(int i = 0 ; i < numOfNodes ; i++){
            Q[i].name = i ;
            Q[i].key = dis[i] ;
            Q[i].flag = true ;
        }
        Dijkstra() ;
        
        cout<<endl;
        cout<<"paths and their costs : "<<endl;

        vector<int> paths[numOfNodes];
        for(int i= 0 ; i< numOfNodes ; i++){
            cout<<" 0 to "<<i<<"  : ";
            printPath_withCost(k, i, i, paths[i]);
        }
        cout<<endl;

    }
    
    return 0 ;
}


