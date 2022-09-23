#include<iostream>
using namespace std;

void sieve(int n, int array[]){
    
    if(n <= 1){
        cout<<"There is no prime number"<<endl;
    }

    for(int i= 2 ; i<= n ; i++){
        if(array[i] == 0){
            for(int j=i*i; j <=n ; j+=i){
                array[j] = 1; // 1 means marked 
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"enter a number: ";
    cin>>n;

    int array[10000];

    for(int i = 0 ; i< 10000 ; i++){
        array[i] = 0; // 0 means unmarked 
    }

    sieve(n, array);

    for(int i = 2; i<= n ; i++){
        if(array[i] == 0){
            cout<<i<<" ";
        }
    }


    return 0;
}
