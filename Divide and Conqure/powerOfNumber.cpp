#include<iostream>
using namespace std;


// devide and conqure approch 

int power(int x,int y){
    if(y == 0){
        return 1;
    }
    int temp = power(x,y/2);
    if(y % 2 == 0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}


int main(int argc, char const *argv[])
{
    int x,y;
    cin>>x>>y;

    cout<<power(x,y);

    return 0;
}


// useless quick sort part

