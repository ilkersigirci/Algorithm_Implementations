/* Approach 1: We start from index 0 and we can visit any of the index from i+1 to i+k,
 hence the minimum cost of all the paths will be stored in dp[i]. 
 Once we reach N-1, it will be our base case. 
 Use memoization to memoize the states, so that 
 we do not need to revisit the state again to reduce complexity.*/
 // C++ implementation of the approach 

//Time Complexity: O(N * K) | Space Complexity : O(N)

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the minimum cost 
// to reach the last index 
int FindMinimumCost(int ind, int a[], int n, int k, int dp[]) { 
  
    // If we reach the last index 
    if (ind == (n - 1)) return 0;         
  
    // Already visited state 
    else if (dp[ind] != -1) return dp[ind]; 
        
    else {   
        int ans = INT_MAX; // Initially maximum   
        
        for (int i = 1; i <= k; i++) { // Visit all possible reachable index   
            
            if (ind + i < n) // If inside range 
                ans = min(ans, abs(a[ind + i] - a[ind]) + FindMinimumCost(ind + i, a, n, k, dp));  
            
            else break; // We cannot move any further                 
        }
        return dp[ind] = ans; // Memoize 
    } 
}

// Driver Code 
int main() 
{ 
    int a[] = { 10, 30, 40, 50, 20 }; 
    int k = 3; 
    int n = sizeof(a) / sizeof(a[0]); 
    int dp[n]; 
    memset(dp, -1, sizeof dp); 
    cout << FindMinimumCost(0, a, n, k, dp); 
  
    return 0; 
}

/////////////////////////////////////////////////////////////////////////////////////////

/* Approach 2: The second approach also requires the use of Dynamic programming. 
This approach is based on Bellman ford’s DP solution to the single-source shortest path. 
In Bellman’s ford SSSP, the main idea is to find the next vertex through minimizing on edges, 
we can do the same we minimize on abs values of two elements of an array to find the next index. */

//Time Complexity: O(N * K) | Space Complexity : O(N)

#include <bits/stdc++.h> 
using namespace std; 
  
// Function for returning the min of two elements 
int min(int a, int b) { 
    return (a > b) ? b : a; 
} 
  
int minCostJumpsDP(vector <int> & A, int k) { 
    
    int size = A.size();  // for calculating the number of elements      
    vector <int> x(size, INT_MAX);  // Allocating Memo table and  initializing with INT_MAX  
    
    x[0] = 0; // Base case 
  
    // For every element relax every reachable  element ie relax next k elements 
    for (int i = 0; i < size; i++) { 
        // reaching next k element 
        for (int j = i + 1; j < i + k + 1; j++) { 
            // Relaxing the element 
            x[j] = min(x[j], x[i] + abs(A[i] - A[j])); 
        } 
    } 
    return x[size - 1]; // return the last element in the array 
}  
// Driver Code 
int main() { 
    vector <int> input { 83, 26, 37, 35, 33, 35, 56 }; 
    cout << minCostJumpsDP(input, 3); 
    return 0; 
}