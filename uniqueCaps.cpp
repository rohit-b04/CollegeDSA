// C++ code to calculate the number of ways 
// to assign caps to people using Tabulation
#include <bits/stdc++.h>
using namespace std;

int numberWays(vector<vector<int>>& caps) {
    int n = caps.size();
    int allMask = (1 << n) - 1; 

    // Create adjacency matrix for cap-to-people distribution
    vector<vector<int>> capToPeople(101);
    for (int i = 0; i < n; ++i) {
        for (int cap : caps[i]) {
            capToPeople[cap].push_back(i);
        }
    }

    // DP table: dp[cap][assignedPeople] 
    // stores the number of ways
    // to assign caps for the first 'cap' 
    // caps with 'assignedPeople' bitmask
    vector<vector<int>> dp(102, vector<int>(1 << n, 0));

    // Base case: With 0 caps, no people assigned, 
    // there's 1 way (do nothing)
    dp[0][0] = 1;

    // Fill the DP table
    for (int cap = 1; cap <= 100; ++cap) {
        
        for (int assignedPeople = 0; 
               assignedPeople <= allMask; ++assignedPeople) {
            
            // If there are no ways to assign caps for
            // this state, continue
            if (dp[cap - 1][assignedPeople] == 0) {
                continue;
            }

            // Case 1: Skip the current cap
            dp[cap][assignedPeople] += dp[cap - 1][assignedPeople];

            // Case 2: Assign current cap to each person who can wear it
            for (int person : capToPeople[cap]) {
                
                // If the person hasn't been assigned a cap yet
                if ((assignedPeople & (1 << person)) == 0) {
                    dp[cap][assignedPeople | (1 << person)] 
                                   += dp[cap - 1][assignedPeople];
                }
            }
        }
    }

    // The result will be in dp[100][allMask], 
    // as we have considered all caps and assigned all people
    return dp[100][allMask];
}

int main() {
    
    vector<vector<int>> caps = {{1, 2, 3}, {1, 2}, {3, 4}, {4, 5}};
    cout << numberWays(caps) << endl;
    return 0;
}