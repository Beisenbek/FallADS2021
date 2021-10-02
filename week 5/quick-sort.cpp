#include <iostream>


using namespace std;


int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j <= r - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}