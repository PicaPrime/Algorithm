#include<iostream>
using namespace std;


// brute force recursive solution
int fiboRecursive(int n){
    if(n == 1 || n == 0){
        return n;
    }
    return fiboRecursive(n-1)+fiboRecursive(n-2);
}


// dp solution 

int dp[100];
int fiboDynamic(int n){
    if(n < 2){
        dp[n] = n;
        return n;
    }
    else if(dp[n] != -1){
        return dp[n];
    }
    else{
        dp[n] = (fiboDynamic(n-1) + fiboDynamic(n-2));
        return dp[n];
    }
}

// this problem doesnt need traceing because the dp array is already filled with solution


int main(int argc, char const *argv[])
{
    int n;
    cout<<"enter a number :";
    cin>>n;
    cout<<"recursive solution: "<<fiboRecursive(n)<<endl;

    // dp solution

    for(int i=0 ; i< n+1 ; i++){
        dp[i] = -1;
    }

    cout<<"dynamic solution: "<<fiboDynamic(n)<<endl;
    cout<<"the fibonacii series: ";
    for(int i=0 ; i< n+1 ; i++){
        cout<<dp[i]<<" ";
    }

    return 0; 
}
