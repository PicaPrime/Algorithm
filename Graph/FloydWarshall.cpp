#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int n = 6;
    int r = 8;

    int arr[n][n][n];

    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            for(int k=0 ; k < n ; k++){
                if(j == k){
                    arr[i][j][k] = 0;
                }
                else{
                    arr[i][j][k] = INT_MAX;
                }
            }
        }
    }


    for(int i=0 ; i< r ; i++){
        int u, v, w;
        cin>>u>>v>>w;

        // for()
    }




    return 0;
}
