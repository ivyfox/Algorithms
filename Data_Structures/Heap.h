template <typename T, int MAX_HEAP_SIZE>
class Heap
{
private:
    T elements[MAX_HEAP_SIZE];
    int n;
private:
    inline void swap(int i, int j);
    inline void make();
    inline void down(int k);
    inline void up(int k);
public:
    Heap(T *arr, int n);
    inline const T& top() const;
    inline void pop();
    inline void push(const T&);
    inline bool empty() const;
    inline int size() const;
};

