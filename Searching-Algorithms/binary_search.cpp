#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int key){
    int l = 0, r  = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] > key){
            r = mid - 1;
        }
        else if(a[mid] < key){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    cout << binary_search(a, 7,42) << endl << endl;
}