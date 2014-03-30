#ifndef _UNION_FIND_SET_H_ 
#define _UNION_FIND_SET_H_ 

class UnionFindSet
{
private:
    int size;
    int *parent;
    int *cardinality;

public:
    UnionFindSet(int n);
    ~UnionFindSet();

    // the "union" operation
    bool merge(int a, int b);

    // the "find" operation
    int find(int a);
    
    // how many disjoint set?
    int count() const;
};

#endif
