#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int dis[100][100] = {INT_MAX};
int par[100][100] = {-1};
int numOfNodes ; // number of vertices
int numOfEdges ; 

vector<struct node> g[100];

struct node{
    int nd;
    int weight;
};

struct myqueue{
    int name;
    int key ;
    bool flag ;
};
struct myqueue Q[100];

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




void Dijkstra(int src){

    dis[src][src] = 0;
    par[src][src] = src;
    while(!isEmpty()){
        int u = pop() ;
        for(int i = 0 ; i < g[u].size() ; i++){
            node t = g[u][i] ;
            int v = t.nd ;
            int w = t.weight ;
            if(dis[src][v] > dis[src][u] + w){
                dis[src][v] = dis[src][u] + w ;
                par[src][v] = u ;
                Q[v].key = dis[src][v] ;
            }
        }
    }

}
int main(int argc, char const *argv[])
{
    
    int n = 6;
    numOfNodes = 6;
    int r = 8;
    numOfEdges = r;


    for (int i = 0; i < r; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        struct node temp;
        temp.nd = v;
        temp.weight = w;
        g[u].push_back(temp);
        temp.nd = u ;
        g[v].push_back(temp) ;
    }

    int arr[3] = {0, 1, 4};

    


    return 0;
}
