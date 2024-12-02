
#include <bits/stdc++.h>
using namespace std;

/* if 0 is present in arr[] then
returns the index of FIRST occurrence
of 0 in arr[low..high], otherwise returns -1 */
int firstZero(vector<int> arr, int low, int high)
{
	if (high >= low)
	{
		// Check if mid element is first 0
		int mid = low + (high - low) / 2;
		if ((mid == 0 || arr[mid - 1] == 1) && 
						arr[mid] == 0)
			return mid;

		// If mid element is not 0
		if (arr[mid] == 1) 
			return firstZero(arr, (mid + 1), high);
		
		// If mid element is 0, but not first 0 
		else
			return firstZero(arr, low, (mid -1));
	}
	return -1;
}

int countZeroes(vector<int> arr, int n)
{
	// Find index of first zero in given array
	int first = firstZero(arr, 0, n - 1);

	// If 0 is not present at all, return 0
	if (first == -1)
		return 0;

	return (n - first);
}

int main()
{
    int n ;
    cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }
	cout << "Count of zeroes is "
		<< countZeroes(arr, n);
	return 0;
}


