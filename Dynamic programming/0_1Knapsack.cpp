#include<bits/stdc++.h>
using namespace std;


int arr[100][100];


int knapSack(int W, int wt[], int val[], int n) { 

       if(n == 0 || W == 0){
           return 0;
       }

       if(arr[n][W] != -1){
        return arr[n][W];
       }
       
        else{
            if(wt[n] <= W){
            return arr[n][W] = max(val[n]+knapSack(W-wt[n],wt,val,n-1),knapSack(W,wt,val,n-1)); 
            }

            else{
                return arr[n][W] = knapSack(W,wt,val,n-1);
            }
        }
}



int main(){
    
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++){
            cin>>wt[i];
        }
        
        for(int i=0 ; i< 100 ; i++){
            for(int j=0 ; j< 100 ; j++){
                arr[i][j] = -1;
            }
        }
        
        cout<<knapSack(w, wt, val, n)<<endl;
        

        
	return 0;
}
