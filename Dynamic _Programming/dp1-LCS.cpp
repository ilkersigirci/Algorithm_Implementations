// Longest Common Subsequence
#include <bits/stdc++.h> 
using namespace std; 
/////////////////////////////////////////////////////////////////////////////////////////
// Naive Recursive Implementation
// Time Complexity -> O(n*2^n)

int max(int a, int b) { return (a > b) ? a : b; }
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_simple( char *X, char *Y, int m, int n ) {  
    if (m == 0 || n == 0)  return 0;         
    if (X[m-1] == Y[n-1])  return 1 + lcs_simple(X, Y, m-1, n-1);        
    else  return max(lcs_simple(X, Y, m, n-1), lcs_simple(X, Y, m-1, n));          
} 
/////////////////////////////////////////////////////////////////////////////////////////
// Dynamic Programming Implementation
// Time Complexity -> O(mn)  -- Space Complexity -> O(mn)

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs_dynamic( char *X, char *Y, int m, int n ) {  
    int L[m + 1][n + 1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in  bottom up fashion. Note that
	L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++){  
        for (j = 0; j <= n; j++){  
            if (i == 0 || j == 0) L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1])  L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);             
        }  
    }         
    /* L[m][n] contains length of LCS  for X[0..n-1] and Y[0..m-1] */    
    return L[m][n];  
}
/////////////////////////////////////////////////////////////////////////////////////////
// Dynamic Programming Implementation -> Memoization
const int maximum = 1000; 
  
// Returns length of LCS for X[0..m-1], Y[0..n-1] memoization applied in recursive solution 
int lcs_memoization(string X, string Y, int m, int n, int dp[][maximum]) 
{ 
    // base case 
    if (m == 0 || n == 0) return 0;        
  
    // if the same state has already been computed 
    if (dp[m - 1][n - 1] != -1) return dp[m - 1][n - 1];        
  
    // if equal, then we store the value of the function call 
    if (X[m - 1] == Y[n - 1]) {  
        // store it in arr to avoid further repetitive work in future function calls 
        dp[m - 1][n - 1] = 1 + lcs_memoization(X, Y, m - 1, n - 1, dp);  
        return dp[m - 1][n - 1];
    } 
    else {  
        // store it in arr to avoid further repetitive work in future function calls 
        dp[m - 1][n - 1] = max(lcs_memoization(X, Y, m, n - 1, dp), 
                               lcs_memoization(X, Y, m - 1, n, dp)); 
  
        return dp[m - 1][n - 1]; 
    } 
}

/////////////////////////////////////////////////////////////////////////////////////////
// Longest Common Increasing Subsequence (Dynamic)

// Returns the length and the LCIS of two arrays arr1[0..n-1] and arr2[0..m-1] 
int LCIS(int arr1[], int n, int arr2[], int m) { 
    // table[j] is going to store length of LCIS ending with arr2[j]. We initialize it as 0,
    int table[m]; 
    for (int j=0; j<m; j++) table[j] = 0; 

    // Traverse all elements of arr1[] 
    for (int i=0; i<n; i++) { 
        
        int current = 0; // Initialize current length of LCIS 
  
        // For each element of arr1[], traverse all elements of arr2[]. 
        for (int j=0; j<m; j++) { 
            // If both the array have same elements. Note that we don't break the loop here.            
            if (arr1[i] == arr2[j]) 
                if (current + 1 > table[j]) table[j] = current + 1;
            /* Now seek for previous smaller common element for current element of arr1 */               
            if (arr1[i] > arr2[j]) 
                if (table[j] > current) current = table[j];                    
        } 
    }  
    // The maximum value in table[] is out result
    return *max_element(table, table+m);
} 
/////////////////////////////////////////////////////////////////////////////////////////
/* Driver code */
int main() {  
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";      
    int m = strlen(X);  
    int n = strlen(Y);  
      
    cout<<"Length of LCS is "<< lcs_dynamic( X, Y, m, n ) << endl ;

	// Memoization
	int dp[m][maximum];      
    memset(dp, -1, sizeof(dp));  // assign -1 to all positions   
    cout << "Length of LCS: " << lcs_memoization(X, Y, m, n, dp); 
      
    return 0;  
}