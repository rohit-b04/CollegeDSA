#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int j = 0;
    cout << "Enter the number of array elements" << endl;
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // j increases only when it encounters on zero element
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}