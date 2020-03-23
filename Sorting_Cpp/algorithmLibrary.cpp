#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
int main() 
{ 
    // Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42, 20, 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n);

	/* Other vector initilizaton methods
	vector<int> vect2{10,20,5,23,42,15};
	vector<int> vect2(vect.begin(),vect.end()); */

	sort(vect.begin(), vect.end());
	sort(vect.begin(), vect.end(), greater<int>());
	reverse(vect.begin(), vect.end());
	cout << *max_element(vect.begin(), vect.end());
    cout << *min_element(vect.begin(), vect.end());
    cout << count(vect.begin(), vect.end(), 20);  

    // find() returns iterator to last address if element not present 
    find(vect.begin(), vect.end(),5) != vect.end()? cout << "\nFound": cout << "\nNot found"; 
	binary_search(vect.begin(), vect.end(), 10); //Tests whether 10 exists in sorted vector or not.
    vect.erase(unique(vect.begin(),vect.end()),vect.end()) // This erases the duplicate occurrences in sorted vector in a single line.
	distance(vect.begin(),desired_position) // It returns the distance of desired position from the first iterator.
	cout << distance(vect.begin(),max_element(vect.begin(), vect.end()));
	return 0; 
}