#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std ;

int dp[100][100] ;

int max(int a, int b)
{
    if(a>b) return a ;
    return b ;
}
int lcs(char s1[], char s2[], int n, int m)
{
    if(n == 0 || m == 0) return 0 ;

    if(dp[n][m] != -1) return dp[n][m] ;

    if(s1[n-1] == s2[m-1]) return dp[n][m] = 1+lcs(s1, s2, n-1, m-1) ;
    else{
        return dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1)) ;
    }
}
int main()
{
    char s1[100], s2[100] ;
    memset(dp, -1, sizeof(dp)) ;
    gets(s1) ;
    gets(s2) ;
    int n = strlen(s1) ;
    int m = strlen(s2) ;
   // for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
   // for(int i = 0 ; i <= m ; i++) dp[0][i] = 0 ;
    int len = lcs(s1, s2, n, m) ;
    printf("LCS length %d\n", len) ;


    cout<<"finished: "<<endl;

}

