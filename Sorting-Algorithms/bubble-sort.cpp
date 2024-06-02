#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    bool swapped = false;
    for(int i = 1; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}

int main()
{
    int a[] = {5, 2, 6, 0, 2, 3, 10};
    int n = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, n);
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}