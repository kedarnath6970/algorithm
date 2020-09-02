
#include "orderSymbolTable.h"

BinarySearchST::BinarySearchST(int capacity) {
    
    keys = (Key[]) new Comparable[capacity];
    values = (Value[]) new Comparable[capacity];
}

int BinarySearchST::size() {
    return N;
}

Value BinarySearchST::get(Key key) {
    if (isEmpty()) return NULL;
    int i = rank(key);
    if (i < N && keys[i].compareTo(key) ==0) return vals[i];
    else return NULL;
}

int BinarySearchST::rank(Key key) {
    int lo = 0, hi = N-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cmp = key.compareTo(keys[mid]);
        if (cmp < 0) hi = mid - 1;
        else if (cmp > 0) low = mid + 1;
        else return mid;
    }
    return lo;
}

void BinarySearchST::put(Key key, Value val) {
    int i = rank(key);
    if (i < N && keys[i].compareTo(key) == 0) {
        vals[i] = val;
        return;
    }

    for (int j = N; j > i; j--) {
        keys[j] = keys[j-1];
        vals[j] = vals[j-1];
    }

    keys[i] = key;
    vals[i] = val;
    N++;
}

void BinarySearchST::del(Key key) {
    
    if (isEmpty()) return;
    
    int i = rank(key);
    if (i < N && keysp[i].compareTo(key) == 0) {
        for(int j = i; j < N-1; j++) {
            keys[j] = keys[j+1];
            vals[j] = vals[j+1]
        }
        N--;
    }
}

Key BinarySearchST::min() {
    return keys[0];
}

Key BinarySearchST::max() {
    return keys[N-1];
}

Key BinarySearchST::select(int k) {
    return keys[k];
}

Key BinarySearchST::celing(Key key) {
    int i = rank(key);
    return keys[i];
}

Key BinarySearchST::floor(Key key) {
    int i = rank(key);
    return keys[i-1];
}

Iterable<Key> BinarySearchST::Keys(Key lo, Key hi) {
    
    Queue<Key> q = new Queue<Key>();
    
    for (int i = rank(lo); i < rank(hi); i++)
        q.enqueue(keys[i])
    
    if (contains(hi) {
        q.enqueue(keys[rank(hi)]);
    }
    return q;
}
