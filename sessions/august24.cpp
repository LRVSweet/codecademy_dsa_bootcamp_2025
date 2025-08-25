#include <bits/stdc++.h>

using namespace std;

vector<int> searchSort (vector<int> &input_array)
{
    for (int i = 0; i < input_array.size(); i++)
    {
        int min_index;
        int min_value;

        for (int j = i; j < input_array.size(); i++)
        {
            if (j == i)
            {
                min_index = j;
                min_value = input_array.at(j);
            }
            else if (input_array.at(j) < min_value)
            {
                min_index = j;
                min_value = input_array.at(j);
            }
        }

        swap(input_array[0], input_array[min_index]);
    }

    return input_array;
}

vector<int> bubbleSort (vector<int> &input_array)
{
    for (int i = 0; i < input_array.size(); i++)
    {
        bool swap_occurred = false;

        for (int j = 0; j < input_array.size() - 1; j++)
        {
            if (input_array.at(j) > input_array.at(j + 1))
            {
                swap(input_array[j], input_array[j + 1]);
                swap_occurred = true;
            }

            // Exits function if the array is already sorted
            if (!swap_occurred)
            {
                return input_array;
            }
        }
    }

    return input_array;
}

/*
vector<int> bubbleSortRecursive (vector<int> input_array, int endIdx)
{
    if (endIdx == 0)
    {

    }
    
    for (int i = 0; i < endIdx; i++)
    {

    }
}
*/

/*
void insertionSort (vector<int> &input_array)
{
    vector<int> new_array = {input_array.at(0)};
    input_array.erase(0);

    while (input_array)
    {

    }


}
*/

// Helper function for mergeSort
void mergeTwoSortedArrays(vector<int> &input_array, int start_index, int mid, int end_index)
{
    vector<int> temp_vector;

    int i = start_index, j = mid + 1;

    while(i <= mid && j <= end_index)
    {

    }
}

vector<int> mergeSort (vector<int> &input_array, int start_index, int end_index)
{
    // Base case
    if (input_array.size() == 1)
    {
        return input_array;
    }

    // Recursive Step
    int mid = start_index + ((end_index - start_index) / 2);
    mergeSort(input_array, start_index, mid);
    mergeSort(input_array, mid + 1, end_index);


}

// Helper function for quickSort
void partition(vector<int> arr, int startIdx, int endIdx)
{

}

void quickSort(vector<int> &arr, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    return;

    int partitionIdx = partition(arr, startIdx, endIdx);
    quickSort(arr, startIdx, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, endIdx)
}

int main ()
{
    vector<int> input_array = {7, 5, 0, 2};
    // searchSort(input_array);
    bubbleSort(input_array);

    cout << "Printing sorted array" << endl;

    for (int element : input_array)
    {
        cout << element << " ";
    }

    cout << endl;

    return 0;
}