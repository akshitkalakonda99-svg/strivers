```cpp
#include <bits/stdc++.h>
using namespace std;

class BinaryHeap {
public:
    int capacity;   // Maximum capacity of heap
    int size;       // Current size
    int* arr;       // Heap array

    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Index helpers
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Insert a new key
    void Insert(int x) {
        if (size == capacity) {
            cout << "Binary Heap Overflow\n";
            return;
        }

        arr[size] = x;
        int k = size;
        size++;

        // Fix min-heap property
        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(arr[parent(k)], arr[k]);
            k = parent(k);
        }
    }

    // Heapify at index i
    void Heapify(int i) {
        int li = left(i);
        int ri = right(i);
        int smallest = i;

        if (li < size && arr[li] < arr[smallest])
            smallest = li;

        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            Heapify(smallest);
        }
    }

    int getMin() {
        return arr[0];
    }

    int ExtractMin() {
        if (size <= 0)
            return INT_MAX;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        Heapify(0);
        return root;
    }

    void DecreaseKey(int i, int val) {
        arr[i] = val;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        DecreaseKey(i, INT_MIN);
        ExtractMin();
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    BinaryHeap h(20);

    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.DecreaseKey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;

    return 0;
}
```
