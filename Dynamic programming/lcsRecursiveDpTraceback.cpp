#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std ;

int dp[100][100] ;
int trace[100][100] ;

int max(int a, int b)
{
    if(a>b) return a ;
    return b ;
}

void traceback(char s1[], char s2[], int n, int m)
{
    if(n == 0 || m == 0) return ;

    if(trace[n][m] == 0){
        traceback(s1,s2,n-1,m-1) ;
        printf("%c", s1[n-1]) ;
    }
    else if(trace[n][m] == 1)
        traceback(s1,s2,n-1,m) ;
    else traceback(s1,s2,n,m-1) ;
}
int lcs(char s1[], char s2[], int n, int m)
{
    if(n == 0 || m == 0) return 0 ;

    if(dp[n][m] != -1) return dp[n][m] ;

    if(s1[n-1] == s2[m-1])
    {
        trace[n][m] = 0 ;
        return dp[n][m] = 1+lcs(s1, s2, n-1, m-1) ;
    }
    else
    {
        int l1 = lcs(s1, s2, n-1, m) ;
        int l2 = lcs(s1, s2, n, m-1) ;
        if(l1>=l2){
            trace[n][m] = 1 ;
            dp[n][m] = l1 ;
        }
        else{
            trace[n][m] = 2 ;
            dp[n][m] = l2 ;
        }
        return dp[n][m] ;

        //return dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1)) ;
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
    cout<<"size of n and m: "<<n<<""<<m<<endl;
    int len = lcs(s1, s2, n, m) ;
    printf("LCS length %d\n", len) ;
    traceback(s1,s2,n,m) ;
}


