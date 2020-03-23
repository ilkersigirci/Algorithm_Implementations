// A C++ program to demonstrate working of sort(), 
// reverse() 
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <numeric> //For accumulate operation 
using namespace std; 
  
// An interval has a start time and end time 
struct Interval 
{ 
    int start, end; 
}; 
  
// Compares two intervals according to staring times. 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
}

int main() 
{ 
    // Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42 , 15}; //sorting array directly ->  sort(arr, arr+n);	
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n);

	/* Other vector initilizaton methods
	vector<int> vect2{10,20,5,23,42,15};
	vector<int> vect2(vect.begin(),vect.end());
	vector<int> vect2(vect); */

    // Sorting the Vector in Ascending order 
    sort(vect.begin(), vect.end());

	//Sorting the Vector in Descending order
	sort(vect.begin(), vect.end(), greater<int>());

    // Reversing the Vector 
    reverse(vect.begin(), vect.end());
  
    cout << "\nMaximum element of vector is: "; 
    cout << *max_element(vect.begin(), vect.end());
  
    cout << "\nMinimum element of vector is: "; 
    cout << *min_element(vect.begin(), vect.end()); 
  
    // Starting the summation from 0 
    cout << "\nThe summation of vector elements is: "; 
    cout << accumulate(vect.begin(), vect.end(), 0);

	/////////////////////////////////////////////////////////////
	// Custom comparison function

	Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
	int size = sizeof(arr)/sizeof(arr[0]); 
  
    // sort the intervals in increasing order of start time
    sort(arr, arr+size, compareInterval);
  
    return 0; 
}