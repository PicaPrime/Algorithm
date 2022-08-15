#include<iostream>
#include<vector>
using namespace std;

    
int main(int argc, char const *argv[]){
    
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    int matrix[n][n];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j< n ; j++){
            matrix[i][j] = 0;
        }
    }

    
    int numberOfEgdes;
    cout<<"enter the numberOfEgdes: ";
    cin>>numberOfEgdes;

    for(int i=0 ; i< numberOfEgdes ; i++){

        int u, v;
        cin>>u>>v;

        matrix[u][v] = matrix[u][v] + 1;
        matrix[v][u] = matrix[v][u] + 1;

    }

    bool flag = false; // if true the graph is multi graph

    for(int i= 0 ; i< n ; i++){
        for(int j=0 ; j< n ; j++){
            if(matrix[i][j] > 1){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        cout<<"multi graph";
    }
    else{
        cout<<"simple graph";
    }

    return 0;
}
