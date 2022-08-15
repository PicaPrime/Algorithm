#include <bits/stdc++.h>
#include<iostream>
using namespace std;


// recursive solution

int sub(string x, string y, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }

    if(x[n] == y[m]){
        return 1+sub(x,y,n-1,m-1);
    }
    else{
        return max(sub(x, y, n-1, m), sub(x, y, n, m-1));
    }

}


// recursive DP solution

int arr[100][100];
int trace[100][100];

int subInDP(string x, string y, int n, int m){

    if(n == 0 || m == 0){
        return 0;
    }

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    if(x[n] == y[m]){
        return arr[n][m] = 1+subInDP(x,y,n-1,m-1);
    }

    else{
        return arr[n][m] = max(subInDP(x, y, n-1, m), subInDP(x, y, n, m-1));
    }

}


int traceBackDP(int n, int m, string x, string y){

    if(n == 0 || m == 0){
        return 0;
    }

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    else{
        if(x[n] == y[m]){
            trace[n][m] = 0;
            return arr[n][m] = 1 + traceBackDP(n-1,m-1,x,y);
        }
        else{
            int l1 = traceBackDP(n-1,m,x,y);
            int l2 = traceBackDP(n,m-1,x,y);

            if(l1 > l2){
                trace[n][m] = 1;
                return arr[n][m] = l1;
            }
            else if(l2 >= l1){
                trace[n][m] = 2;
                return arr[n][m] = l2;
            }
        }
    }
}

void traceFun(int n, int m, string x, string y){

    if(n ==0 || m == 0){
        return;
    }

    if(trace[n][m] == 0){
        traceFun(n-1,m-1,x,y);
    }

    if(trace[n][m] == 1){
        return traceFun(n-1, m, x, y);
    }

    else{
        return traceFun(n, m-1, x, y);
    }

}

int main(int argc, char const *argv[])
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int n = strlen(X);
    int m = strlen(Y);
    cout<<"LCS : "<<sub(X, Y, n, m)<<endl;

   // DP solution
   for(int i=0 ; i< 100 ; i++){
        for(int j=0 ; j< 100 ; j++){
            arr[i][j] = -1;
            trace[i][j] = -1;
        }
   }


   //cout<<"LCS DP solution: "<<subInDP(X, Y, n, m)<<endl;
   cout<<"traceing : "<<endl;
   cout<<traceBackDP(n-1, m-1, X, Y);
   traceFun(n-1, m-1, X, Y);

    return 0;
}
