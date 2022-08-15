// A Recursive C++ program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum
int DP[100];
int trace[100];

int findMinRec(int arr[], int i, int sumCalculated, int sumTotal){
	// If we have reached last element. Sum of one
	// subset is sumCalculated, sum of other subset is
	// sumTotal-sumCalculated. Return absolute difference
	// of two sums.
	if (i == 0){
        trace[i] = 0;
		return DP[i] = abs((sumTotal - sumCalculated) - sumCalculated);
    }

    if(DP[i] != -1){
        return DP[i];
    }

	else{
        int l1 = findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal);
		int l2 = findMinRec(arr, i - 1, sumCalculated, sumTotal);

        if(l1 <= l2){
            trace[i] = 1;
            return DP[i] = l1;
        }
        else{
            trace[i] = 2;
            return DP[i] = l2;
        }
    }
		
}


void TraceFun(int arr[], int i){
    if(i == 0){
        return;
    }

    if(trace[i] == 0){
        //cout<<arr[i]<<" ";
        TraceFun(arr, i-1);
    }

    if(trace[i] == 1){
        cout<<arr[i]<<" ";
        TraceFun(arr, i - 1);
    }

    else{
        TraceFun(arr, i - 1);
    }
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
	// Compute total sum of elements
	int sumTotal = 0;
	for (int i = 0; i < n; i++)
		sumTotal += arr[i];

	// Compute result using recursive function
	return findMinRec(arr, n, 0, sumTotal);
}

// Driver program to test above function
int main()
{
	int arr[] = { 4, 6, 2, 3, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0 ; i< n ; i++){
        DP[i] = -1;
        trace[i] = -1;
    }
	cout << "The minimum difference between two sets is "<< findMin(arr, n);
    cout<<endl;
    TraceFun(arr,n);
	return 0;
}
