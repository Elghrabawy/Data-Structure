#include <bits/stdc++.h>
using namespace std;

struct MinHeap{
    int *array, size, capacity = 1000;
    int left(int node){
        int p = 2 * node + 1;
        return p >= size ? -1 : p;
    }
    int right(int node){
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }
    int parent(int node){
        return node == 0 ? -1 : (node - 1) / 2;
    }
    

};

int main()
{
}