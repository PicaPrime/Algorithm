#include <bits/stdc++.h>
using namespace std;

int dp[100][200];
int traceArr[100][200];

int coin(int S[], int n, int sum){
    if(sum == 0)
        return 0;

    if(n <= 0)
        return 99999;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(S[n - 1] <= sum){
        int l1 = coin(S, n - 1, sum);
        int l2 = 1 + coin(S, n, sum - S[n - 1]);
        if(l1 <= l2){
            traceArr[n][sum] = 1;
            return dp[n][sum] = l1;
        }
        else{
            traceArr[n][sum] = 2;
            return dp[n][sum] = 1 + coin(S, n, sum - S[n - 1]);
        }
    }
    else{
        traceArr[n][sum] = 1;
        return dp[n][sum] = coin(S, n - 1, sum);
    }
}


void trace(int s[], int n, int sum){
    if(n <= 0 || sum <= 0){
        return;
    }

    else if(traceArr[n][sum] == 1){
        return trace(s, n-1, sum);
    }

    else if(traceArr[n][sum] == 2){
        cout<<s[n-1]<<" ";
        trace(s, n, sum-s[n-1]);
    }
}


int main(){
    memset(dp, -1, sizeof(dp));
    memset(traceArr,-1,sizeof(traceArr));
    int arr[] = {1, 5, 10, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 17;
    int mincoins = coin(arr, n, sum);
    if(mincoins == 99999){
        cout << "-1";
    }
    else{
        cout << mincoins;
    }

    cout<<endl;

    trace(arr, n, sum);

}
