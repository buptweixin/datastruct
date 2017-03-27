#ifndef __MAX_HEAP_HPP
#define __MAX_HEAP_HPP
#include "heap.hpp"

template <typename T>
class MaxHeap: public Heap<T>
{
    public:
        MaxHeap(std::vector<T> d):Heap<T>::Heap(d){
            this->build_heap();
        }
        void heap_insert(T key)
        {
            this->data.push_back(key);
            this->heap_size++;
            int i = this->heap_size;
            while (i > 1 && this->data[this->parent(i)] < this->data[i])
            {
                std::swap(this->data[this->parent(i)], this->data[i]);
                i = this->parent(i);
            }
        }

    protected:
        void heapify(int i)
        {
            int l = this->left(i), r = this->right(i);
            int largest = i;
            if (l <= this->heap_size && this->data[l] > this->data[largest])
                largest = l;
            if (r <= this->heap_size && this->data[r] > this->data[largest])
                largest = r;
            if (largest != i)
            {
                std::swap(this->data[largest], this->data[i]);
                i = largest;
                heapify(i);
            }
        }
};
#endif /* ifndef __MAX_HEAP_HPP */
