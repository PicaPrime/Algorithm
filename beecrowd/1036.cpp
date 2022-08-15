#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    double a,b,c;
    cin>>a>>b>>c;
    double d;

    if(a == 0.0 || (b*b - (4*a*c)) < 0){
        cout<<"Impossivel calcular"<<endl;
    }

    else{
        d = (b*b - (4*a*c));
        double x = -b + sqrt(d);
        x = x / (2*a);
        // cout<<setprecision(5)<<x<<endl;
        printf("R1 = %0.5f",x);
        cout<<endl;
        double y = -b - sqrt(d);
        y = y / (2*a);
        // cout<<setprecision(5)<<y<<endl;
        printf("R2 = %0.5f",y);
        cout<<endl;
    }
    return 0;
}
