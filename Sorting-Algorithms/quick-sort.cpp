#include <bits/stdc++.h>
using namespace std;

// make a pivot
int partition_1(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;

    for(int j = l; j <= r; j++){
        if(a[j] < pivot){
            i++;
            swap(a[j], a[i]);
        }
    }

    swap(a[r], a[i + 1]);
    return i + 1;
}
int partition_2(int a[], int l, int r){
    int pivot = a[l];
    int i = l, j = r;

    while(i < j){
        while(a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}

void quick_sort(int a[], int l, int r){
    if(l == r) return;
    if(l < r){
        int pivot = partition_2(a, l, r);
        quick_sort(a, l, pivot - 1);
        quick_sort(a, pivot + 1, r);
    }
    else{
        return;
    }
}

void quick_sort(int a[], int n){
    quick_sort(a, 0, n - 1);
}

int main()
{
    int a[] = {5, 2, 6, 0, 2, 3, 10};
    int n = sizeof(a) / sizeof(a[0]);

    quick_sort(a, n);
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}