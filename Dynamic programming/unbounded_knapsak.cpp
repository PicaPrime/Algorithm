#include<iostream>
using namespace std;

int F(int n, int cap, int w[], int v[]){
    if(n == 0 || cap == 0){
        return 0;
    }

    if(w[n] <= cap){
        return max(v[n]+F(n,cap-w[n],w,v) , F(n-1,cap, w, v));
    }

    else{
        return F(n-1,cap, w, v);
    }
}

int main(int argc, char const *argv[])
{

    int w[4] = {1, 3, 4, 5} ;
    int v[4] = {10, 40, 50, 70};

    int cap = 8;
    int n = 4;

    cout<<F(4, 8, w, v);
    
    return 0;
}
