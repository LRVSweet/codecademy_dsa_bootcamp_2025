#include <iostream>
#include <vector>

using namespace std;

// Attention - Did not terminate
void selectionSort (vector<int> &input_array)
{
    // Defines the boundary of the sorted sublist.
    for (int i = 0; i < input_array.size(); i++)
    {
        int min_val = input_array.at(i);
        int min_index = i;
        
        // Finds the smallest element in the unsorted sublist.
        for (int j = i; j < input_array.size(); j++)
        {
            if (input_array.at(j) < input_array.at(min_index))
            {
                min_val = input_array.at(j);
                min_index = j;
            }
        }

        swap(input_array[i], input_array[min_index]);
    }
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

void insertionSort (vector<int> &input_array)
{
    for (int i = 1; i < input_array.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (input_array.at(j) < input_array.at(j - 1))
            {
                swap(input_array[j], input_array[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

// Helper function for mergeSort
void mergeTwoSortedArrays(vector<int> &input_array, int start_index, int mid, int end_index)
{
    vector<int> temp_vector;

    int i = start_index, j = mid + 1;

    while (i <= mid && j <= end_index)
    {
        if (input_array.at(i) < input_array.at(j))
        {
            temp_vector.push_back(input_array.at(i++));
        }
        else
        {
            temp_vector.push_back(input_array.at(j++));
        }
    }

    for (; i<= mid; i++)
    {
        temp_vector.push_back(input_array.at(i));
    }

    for (; j<= end_index; j++)
    {
        temp_vector.push_back(input_array.at(j));
    }

    // Copy temp_vector into input_array
    int k = start_index;
    for (int element : temp_vector)
    {
        input_array[k++] = element;
    }
}

void mergeSort (vector<int> &input_array, int start_index, int end_index)
{
    // Base case
    if (start_index >= end_index)
    return;

    // Recursive Step
    int mid = start_index + ((end_index - start_index) / 2);
    mergeSort(input_array, start_index, mid);
    mergeSort(input_array, mid + 1, end_index);

    mergeTwoSortedArrays(input_array, start_index, mid, end_index);
}

// Helper function for quickSort
int partition(vector<int> &arr, int startIdx, int endIdx)
{
    int pivot = arr.at(startIdx);

    int lower_part_index = startIdx;
    int higher_part_index = endIdx;

    while (lower_part_index < higher_part_index)
    {
        while (arr.at(lower_part_index) <= pivot && lower_part_index < endIdx)
        lower_part_index++;

        while (arr.at(higher_part_index) > pivot && higher_part_index > startIdx)
        higher_part_index--;

        if (lower_part_index < higher_part_index)
        swap(arr[lower_part_index], arr[higher_part_index]);
    }

    // Why does it have to be the higher_part_index that is swapped?
    swap(arr[startIdx], arr[higher_part_index]);

    return higher_part_index;
}

void quickSort(vector<int> &arr, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    return;

    int partitionIdx = partition(arr, startIdx, endIdx);
    quickSort(arr, startIdx, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, endIdx);
}

int main ()
{
    vector<int> input_array = {7, 5, 9, 2, 10, 88, 17, -1, 7};
    selectionSort(input_array);

    cout << "Printing sorted array" << endl;

    for (int element : input_array)
    {
        cout << element << " ";
    }

    cout << endl;

    return 0;
}