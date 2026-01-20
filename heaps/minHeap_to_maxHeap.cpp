#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void convertMinToMaxHeap(vector<int>& a)
{
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);
}

int main()
{
    vector<int> minHeap = {1, 3, 5, 7, 9, 8};

    convertMinToMaxHeap(minHeap);

    for (int x : minHeap)
        cout << x << " ";
}
