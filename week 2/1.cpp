#include <iostream>

using namespace std;

void print(int * a, int n){
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
}

void print2(int * a, int i, int n){
    if(i < n){
        cout << a[i] << " ";
        print2(a, i + 1, n);
    }
}

int main(){

    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(int);

    print(a, n);

    cout << endl;

    print2(a, 0, n);


    return 0;
}