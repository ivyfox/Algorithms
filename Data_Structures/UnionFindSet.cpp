#include "UnionFindSet.h"

UnionFindSet::UnionFindSet(int n):size(n) 
{
    parent = new int[size];
    cardinality = new int[size];
    for (int i=0; i<size; i++) {
        parent[i] = i;
        cardinality[i] = i;
    }
}

UnionFindSet::~UnionFindSet()
{
    delete []parent;
    delete []cardinality;
}

bool UnionFindSet::merge(int a, int b) 
{
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) {
        return false;
    }
    else { // weighted-union
        int ca = cardinality[ra];
        int cb = cardinality[rb];
        if (ca < cb) {
            parent[ra] = rb;
            cardinality[rb] += cardinality[ra];
        }
        else {
            parent[rb] = ra;
            cardinality[ra] += cardinality[rb];
        }
        return true;
    }
}

int UnionFindSet::find(int a)
{
    if (parent[a] != a) {
        parent[a] = find(parent[a]); // path compression
    }
    return parent[a];
}

int UnionFindSet::count() const
{
    int cnt = 0;
    for (int i=0; i<size; i++) {
        if (parent[i] == i) cnt ++;
    }
    return cnt;
}

