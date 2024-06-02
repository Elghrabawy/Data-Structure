#include <bits/stdc++.h>
using namespace std;

int smallest(int a[], int start, int end){
    int min_i = start;
    for(int i = start + 1; i < end; i++){
        if(a[i] < a[min_i]){
            min_i = i;
        }
    }
    return min_i;
}

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallest_i = smallest(a, i, n);
        swap(a[i], a[smallest_i]);
    }
}

int main()
{
    int a[] = {5, 2, 6, 0, 2, 3, 10};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}