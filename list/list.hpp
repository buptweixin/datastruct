#ifndef __LIST_HPP
#define __LIST_HPP
#include <vector>
#include <iostream>

template<typename T>
struct Node
{
    Node() = default;

    Node(T v){
        val = v;
        prev = NULL;
        next = NULL;
    }
    Node *prev, *next;
    T val;
};

template<typename T>
class List
{
    public:
        List(){
            NIL = new Node<T>(0);
            NIL->next = NIL;
            NIL->prev = NIL;
        }
        ~List() = default;
        Node<T>* list_search(const T &key);
        void list_delete(Node<T> *x);
        void list_insert(T x);

        void print()
        {
            Node<T> *h = NIL->next;
            while(h != NIL)
            {
                std::cout << h->val << std::endl;
                h = h->next;
            }
        }

        Node<int> *getHead()
        {
            return NIL;
        }
    private:
        Node<T> *NIL;
};


template <typename T>
Node<T>* List<T>::list_search(const T &key)
{
    Node<T> *x = NIL->next;
    while(x->val != key && x->next != NIL)
        x =  x->next;
    return x;
}

template<typename T>
void List<T>::list_insert(T val)
{
    Node<T> *x = new Node<T>(val);
    x->next = NIL->next;
    x->prev = NIL;
    NIL->next = x;
    NIL->next->prev = x;
}

template<typename T>
void List<T>::list_delete(Node<T> *x)
{
    x->next->prev = x->prev;
    x->prev->next = x->next;
}
#endif /* ifndef __LIST_HPP */
