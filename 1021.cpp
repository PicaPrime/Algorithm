#include<iostream>
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    
    double n;
    cin>>n;

    double array[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
    
    cout<<"NOTAS:"<<endl;
    for(int i=0 ; i < 6 ; i++){
        int x = n / array[i];
        n = n - (x * array[i]);
        cout<<x<<" nota(s) de R$ ";
        printf("%0.2f\n",array[i]);
    }

    cout<<"MOEDAS:"<<endl;
    for(int i=6 ; i< 12 ; i++){
        int x = n / array[i];
        n = n - (x * array[i]);
        cout<<x<<" moeda(s) de R$ ";
        printf("%.2f\n",array[i]);
    }
    return 0;
}
