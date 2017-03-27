#ifndef __MIN_HEAP_HPP
#define __MIN_HEAP_HPP
#include "heap.hpp"

template <typename T>
class MinHeap : public Heap<T>
{
    public:
        MinHeap(std::vector<T> d):Heap<T>::Heap(d)
    {
        this->build_heap();
    }

        void heap_insert(T key)
        {
            this->data.push_back(key);
            this->heap_size++;
            int i = this->heap_size;
            while (i > 1 and this->data[this->parent(i)] > this->data[i])
            {
                std::swap(this->data[this->parent(i)], this->data[i]);
                i = this->parent(i);
            }
        }

        T extract_min()
        {
            if (this->heap_size < 1)
                throw "this heap is empty!";
            T min = this->data[1];
            std::swap(this->data[1], this->data[this->heap_size]);
            this->heap_size--;
            heapify(1);
            return min;
        }

    protected:
        void heapify(int i)
        {
            int smallest = i;
            int l = this->left(i), r = this->right(i);
            if (l <= this->heap_size and this->data[smallest] > this->data[l])
                smallest = l;
            if (r <= this->heap_size and this->data[smallest] > this->data[r])
                smallest = r;
            if (smallest != i)
            {
                std::swap(this->data[i], this->data[smallest]);
                i = smallest;
                heapify(i);
            }
        }
};

#endif /* ifndef __MIN_HEAP_HPP */
