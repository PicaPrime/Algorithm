#include<iostream>
using namespace std;

//without DP
int fibo(int n){
    if(n <= 1){
        return 1;
    }
    return fibo(n-1)+fibo(n-2);
}


//with DP
// this array is decleared as golobal 

int arr[100];

int fibonacci(int n){
    if(n <= 1){
        return 1;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    return arr[n] = fibonacci(n-1)+fibonacci(n-2);
}

int main(int argc, char const *argv[])
{

    for(int i=0 ; i< 100; i++){
        arr[i] = -1;
    }

    cout<<fibo(6);
    cout<<endl<<"with dp: "<<fibonacci(6);
    return 0;
}
