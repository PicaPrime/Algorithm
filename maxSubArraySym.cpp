#include<iostream>
#include<array>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[8] = {-1, 2, 4, -3, 5, 2, -5, 2};

    int maxSubArrSum = 0;
    
    // complexity O(n^3)

    for(int i = 0 ; i < 8 ; i++){
        for(int j = i ; j < 8 ; j++){
            int sum = 0;
            for(int k = i ; k <= j ; k++){
                sum = sum + arr[k];
            }
            if(sum > maxSubArrSum){
                maxSubArrSum = sum;
            }
        }
    }

    cout<<maxSubArrSum;
    cout<<endl;
    int arrr[5] = {1,2,3,4,5};

    maxSubArrSum = 0;

    // complixity O(n^2)
    for(int  i = 0 ; i< 8 ; i++){
        int sum = 0;
        for(int j = i ; j < 8; j++){
            sum = sum + arr[j];
            if(sum > maxSubArrSum){
                maxSubArrSum = sum;
            }
        }
    }

    cout<<maxSubArrSum;
    cout<<endl;

    maxSubArrSum = 0; 
    int sum = 0;

    //complixity O(n) 
    // best one yet
    for(int i=0 ; i< 8 ; i++){
        sum = max(arr[i], sum + arr[i]);
        maxSubArrSum = max(sum, maxSubArrSum);
    }

    cout<<maxSubArrSum;
    return 0;
}
