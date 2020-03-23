/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std;  
  
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int* arr, int start, int end)  // Lomuto’s Partition Scheme
{  
    int pivot = arr[end]; // pivot 
    int i = start;  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            swap(&arr[i], &arr[j]);  
            i++; // increment index of smaller element  
        }  
    }
    swap(&arr[i], &arr[end]);
    return i;  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
start --> Starting index,  
end --> Ending index */
void quickSort(int* arr, int start, int end)  
{  
    if (start < end)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, start, end);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, start, pi - 1);  
        quickSort(arr, pi + 1, end);  
    }  
}  
///////////////////////////////////////////////////////////////////////////
// Optimized Recursive QuickSort
void quicksort_optimized(int * tab, int l, int r){
   int q;
   while(l < r){
      q = partition(tab, l, r);
      if(q - l < r - q){ //recurse into the smaller half      
         quicksort(tab, l, q - 1);
         l = q + 1;
      }
	  else{
         quicksort(tab, q + 1, r);
         r = q - 1;
      }
   }
}
///////////////////////////////////////////////////////////////////////////
// An iterative implementation of quick sort 

/* A[] --> Array to be sorted,  
l --> Starting index,  
h --> Ending index */
void quickSortIterative(int* arr, int l, int h) 
{ 
    // Create an auxiliary stack 
    int stack[h - l + 1]; 
  
    // initialize top of stack 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = l; 
    stack[++top] = h; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p = partition(arr, l, h); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
}
///////////////////////////////////////////////////////////////////////////
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver Code 
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}