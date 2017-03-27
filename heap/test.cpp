#include "heap.hpp"
#include "max_heap.hpp"
#include "min_heap.hpp"

using namespace std;

int main()
{
    int num;
    vector<int> input;
    while (cin >> num)
        input.push_back(num);
    MaxHeap<int> heap(input);
    cout << "maxheap:" << endl;
    heap.print();
    cout << "minHeap:" << endl;
    MinHeap<int> heapmin(input);
    heapmin.print();
    cout << "insert -10:" << endl;
    heapmin.heap_insert(-10);
    heapmin.print();
    cout << "after sorted:" << endl;
    heapmin.heap_sort();
    heapmin.print();
}
