
#include <bits/stdc++.h>
using namespace std;

int findMinRec(int arr[], int i, int sumCalculated, int sumTotal){
	
	if (i == 0)
		return abs((sumTotal - sumCalculated) - sumCalculated);

	return min(
		findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal),
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
	cout << "The minimum difference between two sets is "<< findMinRec(arr, n, 0, sumTotal);
    
	return 0;
}
