#ifndef __HEAP_HPP
#define __HEAP_HPP

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Heap
{
    public:
        Heap(std::vector<T> d):heap_size(d.size())
        {
            data.resize(d.size() + 1);
            for (int i = 1; i <= d.size(); ++i)
                data[i] = d[i-1];
        }

        virtual ~Heap() = default;

        void print()
        {
            for (T num : data)
                std::cout << num << std::endl;
        }

        virtual void heap_insert(T key)
        {

        }

        void heap_sort()
        {
            while (heap_size > 1)
            {
                std::swap(data[1], data[heap_size]);
                heap_size--;
                heapify(1);
            }
        }

    protected:
        virtual void heapify(int i)
        {
        }

        void build_heap()
        {
            for (int i = heap_size / 2; i > 0; --i)
                heapify(i);
        }

        inline int left(int i) const
        {
            return i * 2;
        }

        inline int right(int i) const
        {
            return i * 2 + 1;
        }

        inline int parent(int i) const
        {
            return i / 2;
        }

        std::vector<T> data;
        size_t heap_size;
};
#endif /* ifndef __HEAP_HPP*/
