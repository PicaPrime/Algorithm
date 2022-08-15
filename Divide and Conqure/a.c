#include<stdio.h>
#include<math.h>


int main(int argc, char const *argv[])
{
    
   int arr[3];

   for(int i=0 ; i <3 ; i++){
        scanf("%d",&arr[i]);
   }

   for(int i=0 ; i< 3 ; i++){
        for(int j=i+1 ; j< 3 ; j++){
            if(arr[i] > arr[j]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
   }

    printf("max :%d\n",arr[2]);
    printf("mid: %d\n",arr[1]);
    printf("min: %d\n",arr[0]);


    return 0;
}
