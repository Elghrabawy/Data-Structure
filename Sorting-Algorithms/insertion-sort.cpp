#include <bits/stdc++.h>
using namespace std;

void insertion_sort_1(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        while(j >= 0 && a[j] > a[j + 1]){
            swap(a[j], a[j + 1]);
            j--;
        }
    }
}

void insertion_sort_2(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1, key = a[i];
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {5, 2, 6, 0, 2, 3, 10};
    int n = sizeof(a) / sizeof(a[0]);

    insertion_sort_2(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}