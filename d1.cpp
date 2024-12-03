// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the unique subsets
vector<vector<int> > solve(vector<int>& v)
{
    // To store the resulting subsets
    set<vector<int> > res;
    vector<int> subset;
    int size = v.size();

    // Finding 2^N
    int N = 1 << size;
    for (int i = 1; i < N; i++) {

        int bit = i;
        subset.clear();
        int pos = 0;

        while (bit) {

            // If the bit is set inset
            // it into the subset
            if (bit & 1) {
                subset.push_back(v[pos]);
            }
            pos++;
            bit >>= 1;
        }
        res.insert(subset);
    }

    vector<vector<int> > result;
    for (auto u : res)
        result.push_back(u);
    return result;
}

// Driver code
int main()
{
    vector<int> A = { 1, 2, 2 };

    // Function call
    vector<vector<int> > result = solve(A);
    for (auto v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}