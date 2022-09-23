// A Recursive C++ program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

int DP[100][100];

int findMinRec(int arr[], int i, int sumCalculated,
			int sumTotal)
{
	// If we have reached last element. Sum of one
	// subset is sumCalculated, sum of other subset is
	// sumTotal-sumCalculated. Return absolute difference
	// of two sums.
	if (i == 0){
		return abs((sumTotal - sumCalculated) - sumCalculated);
    }
	// For every item arr[i], we have two choices
	// (1) We do not include it first set
	// (2) We include it in first set
	// We return minimum of two choices
	return min(
		findMinRec(arr, i - 1, sumCalculated + arr[i - 1],
				sumTotal),
		findMinRec(arr, i - 1, sumCalculated, sumTotal));
}


int main()
{
	int arr[] = { 3, 1, 4, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

    int sumTotal = 0;
	for (int i = 0; i < n; i++){
		sumTotal += arr[i];
    }

    for(int i=0 ; i<= n ; i++){
        for(int j=0 ; j<= n ; j++){
            DP[i][j] = -1;
        }
    }


	cout << "The minimum difference between two sets is "<< findMinRec(arr, n, 0, sumTotal);
    
	return 0;
}
