#include <bits/stdc++.h>
#include<iostream>
using namespace std;


// recursive sollution

int sub(string x, string y, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }

    if(x[n-1] == y[m-1]){
        return 1+sub(x,y,n-1,m-1);
    }
    else{
        return max(sub(x, y, n-1, m), sub(x, y, n, m-1));
    }
}


// DP solution
int arr[100][100];

int subInDP(string x, string y, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    if(x[n-1] == y[m-1]){
        return arr[n][m] = 1+subInDP(x,y,n-1,m-1);
    }

    else{
        return arr[n][m] = max(subInDP(x, y, n-1, m), subInDP(x, y, n, m-1));
    }

}


// solution for tracking back or tracing the LCS string

int traceArr[100][100];

int traceBackDP(int n, int m, string x, string y){

    if(n == 0 || m == 0){
        return 0;
    }

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    else{
        if(x[n-1] == y[m-1]){
            traceArr[n][m] = 0;
            return arr[n][m] = 1 + traceBackDP(n-1,m-1,x,y);
        }
        else{
            int l1 = traceBackDP(n-1,m,x,y);
            int l2 = traceBackDP(n,m-1,x,y);

            if(l1 >= l2){
                traceArr[n][m] = 1;
                return arr[n][m] = l1;
            }
            else if(l2 > l1){
                traceArr[n][m] = 2;
                return arr[n][m] = l2;
            }
        }
    }
}

void trace(string x, string y, int n, int m){
    
    if(n == 0 || m == 0){
        return;
    }

    if(traceArr[n][m] == 0){
        trace(x, y, n-1, m-1);
        cout<<x[n-1];
    }

    else if(traceArr[n][m] == 1){
        trace(x, y, n-1, m);
    }

    else{
        trace(x, y, n, m-1);
    }

}


int main(int argc, char const *argv[])
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int n = strlen(X);
    int m = strlen(Y);
    cout<<"size of both strings: "<<n<<" "<<m<<endl;
    cout<<"recursive solution answer: ";
    cout<<sub(X, Y, n, m)<<endl;

    // initializing dp array with -1
    for(int i=0 ; i<= n; i++){
        for(int j=0 ; j<= m ; j++){
            arr[i][j] = -1;
        }
    }
    
    cout<<"dynamic solution answer: ";
    cout<<subInDP(X, Y, n, m)<<endl;

    for(int i=0 ; i<= n ; i++){
        for(int j=0 ; j<= m ; j++){
            arr[i][j] = -1;
            traceArr[i][j] = -1;
        }
    }

    cout<<"solution in DP with traceing: ";
    cout<<traceBackDP(n, m, X, Y)<<endl;
    cout<<"the lcs string is :";
    trace(X, Y, n, m);

    return 0;
}
