#include <iostream>

using namespace std;

class MinHeap {
public:
    // Constructor - int capacity input
    MinHeap(int requested_capacity) {
        _size = 0;
        _capacity = requested_capacity;
        _array = new int [requested_capacity];
    }

    // Constructor - int* array + int size input
    MinHeap(int* input_array, int size) {
        _size = size;
        _capacity = size;
        _array = input_array;

        for (int i = size - 1; i >= 0; i--) {
            _heapify(i);
        }
    }

    void insert(int value) {
        if (_size == _capacity) {
            cout << "Heap is full." << endl;
            return;
        }

        int index = _size++;

        _array[index] = value;

        while (index > 0 && _array[_parent(index)] > _array[index]) {
            swap(_array[_parent(index)], _array[index]);
            index = _parent(index);
        }
    }

    int getSize() {
        return _size;
    }

    int* getArray() {
        return _array;
    }

    int top() {
        return _array[0];
    }

    void pop() {
        swap(_array[_size - 1], _array[0]);
        _size--;

        _heapify(0);
    }

    void heapSort() {
        int original_size = _size;
        for (int i = 0; i < original_size; i++) {
            pop();
        }
    }

    void print() {
        for (int i = 0; i < _size; i++) {
            cout << _array[i] << " ";
        }

        cout << endl;
    }

private:
    int _size;
    int _capacity;
    int* _array;

    int _parent(int index) {
        return (index - 1) / 2;
    }

    int _left(int index) {
        return index * 2 + 1;
    }

    int _right(int index) {
        return index * 2 + 2;
    }

    void _heapify(int index) {
        int min_index = index;

        int left = _left(index);
        if (left < _size && _array[left] < _array[min_index]) {
            min_index = left;
        }

        int right = _right(index);
        if (right < _size && _array[right] < _array[min_index]) {
            min_index = right;
        }

        if (min_index != index) {
            swap(_array[index], _array[min_index]);
            _heapify(min_index);
        }
    }
};

void printArray (int* array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main () {
    int my_array[] = {1, 2, 3, 4, 5};
    MinHeap my_heap(my_array, 5);
    
    int* array_from_heap = my_heap.getArray();
    int array_size = my_heap.getSize();
    my_heap.heapSort();

    printArray(array_from_heap, array_size);
}