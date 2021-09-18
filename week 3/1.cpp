#include <iostream>

using namespace std;

int bs(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - 1) / 2;
        //int m = (l + r ) / 2;
        if(arr[m] == x) return m;
        if(arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int bs2(int arr[], int l, int r, int x){
    if(l > r) return -1;
    int m = (l + r) / 2;
    if(arr[m] == x) return m;
    if(arr[m] < x) return bs2(arr, m + 1, r, x);
    return bs2(arr, l, m - 1, x);
}


int main(){

    int arr[] = {2, 3, 4, 10, 40};
    int x;
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < 100; ++i){
        x = i;
        cout << x << ": ";
        cout << bs(arr, 0, n - 1, x) << " ";
        cout << bs2(arr, 0, n - 1, x) << endl;
    }

    return 0;
}