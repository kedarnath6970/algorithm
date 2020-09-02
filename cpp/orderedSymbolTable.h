#ifndef __SortedSymbolTable_H__
#define __SortedSymbolTable_H__


class BinarySearchST {
    public:
        BinarySearchST(int capacity);
        int size();
        Value get(Key key);
        int rank(Key key);
        void put(Key key, Value value);
        void del(Key key);
        Key min();
        Key max();
        Key select();
        Key ceiling(Key key);
        Key floor(Key key);
        Key del(Key key);
        Iterable<Key> keys(Key lo, Key hi);


    private:
        Key[] keys;
        Value[] vals;
        int N;
};
