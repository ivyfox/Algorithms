#include "Heap.h"

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::swap(int i, int j) 
{
    T temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
}

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::make() 
{
    for (int i=n/2; i>=1; i--) {
        down(i);
    }
}

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::down(int k)
{
    while (k <= n / 2) {
        int p = k * 2;
        if (p + 1 <= n && elements[p] > elements[p+1]) p ++;
        if (elements[k] < elements[p]) return;
        swap(k, p);
        k = p;
    }
}

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::up(int k)
{
    while (k > 1) {
        if (elements[k] >= elements[k/2]) return;
        swap(k , k / 2);
        k /= 2;
    }
}

template <typename T, int MAX_HEAP_SIZE>
Heap<T, MAX_HEAP_SIZE>::Heap(T *arr, int s):n(s)
{
    for (int i=0; i<n; i++) {
        elements[i+1] = arr[i];
    }
    make();
}

template <typename T, int MAX_HEAP_SIZE>
const T& Heap<T, MAX_HEAP_SIZE>::top() const 
{
    return elements[1];
}

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::pop()
{
    swap(1, n--);
    down(1);
}

template <typename T, int MAX_HEAP_SIZE>
void Heap<T, MAX_HEAP_SIZE>::push(const T& t)
{
    elements[++n] = t;
    up(n);
}

template <typename T, int MAX_HEAP_SIZE>
bool Heap<T, MAX_HEAP_SIZE>::empty() const
{
    return n == 0;
}

template <typename T, int MAX_HEAP_SIZE>
int Heap<T, MAX_HEAP_SIZE>::size() const 
{
    return n;
}

