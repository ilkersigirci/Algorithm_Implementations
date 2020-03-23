#include <iostream>
#include <vector>

//function to swap values
//need to pass by reference to sort the original values and not just these copies
void Swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort (std::vector<int> &array)
{
    std::cout<<"Elements in the array: "<<array.size()<<std::endl;

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {   
            if (array[j] > array[j+1])
                Swap(&array[j], &array[j+1]);
        }
    }
}

//function to print the array
void PrintArray (std::vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    std::cout<<"Enter array to be sorted (-1 to end)\n";

    std::vector<int> array;
    int num = 0;
    while (num != -1)
    {
        std::cin>>num;
        if (num != -1)
            //add elements to the vector container
            array.push_back(num);
    }
	std::cout << array.size() << std::endl;

    //sort the array
    BubbleSort(array);

    std::cout<<"Sorted array is as\n";
    PrintArray(array);

    return 0;
}
