// Ugly numbers are numbers whose only prime factors are 2, 3 or 5
# include<bits/stdc++.h> 
using namespace std; 
///////////////////////////////////////////////////////////
// Simple Version	
/*This function divides a by greatest divisible power of b*/
int maxDivide(int a, int b) { 
	while (a%b == 0) a = a/b;	 
	return a; 
}     
	
/* Function to check if a number is ugly or not */
int isUgly(int no) { 
	no = maxDivide(no, 2); 
	no = maxDivide(no, 3); 
	no = maxDivide(no, 5); 
	
	return (no == 1)? 1 : 0; 
}     
	
/* Function to get the nth ugly number*/
int getNthUglyNo_Simple(int n) {
	int i = 1;  
	int count = 1;   /* ugly number count */ 
	
	/*Check for all integers untill ugly count  
	becomes n*/ 

	while (n > count){ 
		i++;       
		if (isUgly(i)) count++;       
	}
	return i; 
}
///////////////////////////////////////////////////////////
// Dynamic Programming Version
unsigned getNthUglyNo_Dynamic(unsigned n) 
{ 
    unsigned ugly[n]; // To store ugly numbers 
    unsigned i2 = 0, i3 = 0, i5 = 0; 
    unsigned next_multiple_of_2 = 2; 
    unsigned next_multiple_of_3 = 3; 
    unsigned next_multiple_of_5 = 5; 
    unsigned next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (int i=1; i<n; i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, 
                           min(next_multiple_of_3, next_multiple_of_5)); 
       ugly[i] = next_ugly_no; 
       if (next_ugly_no == next_multiple_of_2) 
       { 
           i2 = i2+1; 
           next_multiple_of_2 = ugly[i2]*2; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
           i3 = i3+1; 
           next_multiple_of_3 = ugly[i3]*3; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = ugly[i5]*5; 
       } 
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no; 
} 
///////////////////////////////////////////////////////////
/* Driver program to test above functions */
int main() { 
	unsigned no = getNthUglyNo_Dynamic(150); 
	printf("150th ugly no. is %d ",  no); 
	getchar(); 
	return 0; 
}
