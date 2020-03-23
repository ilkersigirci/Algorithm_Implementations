/* Memoized version -> Top Down*/

#include <bits/stdc++.h> 
using namespace std; 
#define NIL -1  
#define MAX 100  
  
int lookup[MAX];  
  
/* Function to initialize NIL values in lookup table */
void _initialize(){  
    for (int i = 0; i < MAX; i++)  lookup[i] = NIL;         
}
  
/* function for nth Fibonacci number */
int fib_memoized(int n){  
    if (lookup[n] == NIL){  
        if (n <= 1)  lookup[n] = n;            
        else lookup[n] = fib_memoized(n - 1) + fib_memoized(n - 2);            
	}  
	return lookup[n];  
}  
////////////////////////////////////////////////////////////////////
/* Tabulated version -> Bottom Up */

int fib_tabulated(int n){ 
  int f[n+1]; 
  int i; 
  f[0] = 0;   f[1] = 1;  
  for (i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2]; 
  
  return f[n]; 
} 
////////////////////////////////////////////////////////////////////
// Driver code 
int main (){  
    int n = 40;  
    _initialize();  
    cout << "Fibonacci number is " << fib_memoized(n);  
    return 0;  
}
