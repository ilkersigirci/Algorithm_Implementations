// Longset Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
// Naive Recursive Implementation
// Time Complexity -> O(2^n)  ---  Space Complexity -> O(n)z

/* To make use of recursive calls, this function must return two things: 
   1) Length of LIS ending with element arr[n-1]. We use max_ending_here for this purpose      
   2) Overall maximum as the LIS may end with an element before arr[n-1] max_ref is used this purpose.
   The value of LIS of full array of size n is stored in max_ref which is our final result */
int _lis( int arr[], int n, int *max_ref) {    
    if (n == 1)	return 1;  /* Base case */     
    int res, max_ending_here = 1;  // 'max_ending_here' is length of LIS ending with arr[n-1] 

    /* Recursively get all LIS ending with arr[0], arr[1] ...arr[n-2]. If arr[i-1] is smaller than arr[n-1], 
	and max ending with arr[n-1] needs to be updated, then update it */
    for (int i = 1; i < n; i++) { 
        res = _lis(arr, i, max_ref); 
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here) 
            max_ending_here = res + 1; 
    }  
    // Compare max_ending_here with the overall max. And update the overall max if needed
    if (*max_ref < max_ending_here) *max_ref = max_ending_here;    
    return max_ending_here; // Return length of LIS ending with arr[n-1]
}  
// The wrapper function for _lis() 
int lis_simple(int arr[], int n) {    
    int max = 1; // The max variable holds the result     
    _lis( arr, n, &max ); // The function _lis() stores its result in max  
    return max; 
} 
/////////////////////////////////////////////////////////////////////////////////////////
// Dynamic Programming Implementation
// Time Complexity -> O(n^2)  ---  Space Complexity -> O(n)
int lis_dynamic( int arr[], int n ) {  
    int lis[n];   
    lis[0] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ ) { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  lis[i] = lis[j] + 1;                
    }
    return *max_element(lis, lis+n); // Return maximum value in lis[] 
}  
/////////////////////////////////////////////////////////////////////////////////////////
//Using Longest Common Subsequence Algorithm

// Function to return the size of the longest increasing subsequence 
int LIS_usingLCS(vector<int>& seq) { 
    int n = seq.size(); 
  
    // Create an 2D array of integer for tabulation 
    vector<vector<int> > L(n + 1, vector<int>(n + 1));  
    // Take the second sequence as the sorted sequence of the given sequence 
    vector<int> sortedseq(seq);  
    sort(sortedseq.begin(), sortedseq.end()); 
  
    // Classical Dynamic Programming algorithm for Longest Common Subsequence
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (seq[i - 1] == sortedseq[j - 1]) L[i][j] = L[i - 1][j - 1] + 1; 
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    }
    return L[n][n]; 
}

/////////////////////////////////////////////////////////////////////////////////////////
/* Driver program to test above function */
int main() { 
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Length of lis is %dn \n", lis_dynamic( arr, n ));        
    return 0; 
}