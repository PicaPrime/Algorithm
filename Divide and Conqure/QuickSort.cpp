#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int partitiaion(int arr[], int p, int r){
    int i = p-1;
    int x = arr[r];
    for(int j=p  ; j<= (r-1) ; j++){
        if(arr[j] <= x){
            i = i+1;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[r]);
    print(arr,6);
    cout<<"q: "<<i+1<<endl;
    return i+1;
}

void Quicksort(int arr[], int p , int r){
    if(r <= p){
        return;
    }
    int q = partitiaion(arr,p,r);
    partitiaion(arr, p, q-1);
    partitiaion(arr, q+1, r);
}


int main(int argc, char const *argv[])
{

    int arr[6] = {7,3,1,8,9,4};
    Quicksort(arr,0,5);
    cout<<"final output: "<<endl;
    for(int i=0; i< 6 ; i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}
