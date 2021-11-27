#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n][n];
    int inf = 100000;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 0){
                a[i][j] = inf;
            }
        }
    }

    bool used[n];
    int min_e[n];
    int path[n];

    for(int i = 0; i < n; ++i){
        used[i] = false;
        min_e[i] = inf;
        path[i] = -1;
    }
    
    min_e[0] = 0;

    for(int i = 0; i < n; ++i){
        int v = -1;
        for(int j = 0; j < n; ++j){
            if(!used[j] && (v == -1 || min_e[j] < min_e[v])){
                v = j;
            }
        }
        if(min_e[v] >= inf){
            cout << "No MST!";
            return 0;
        }
        used[v] = true;
        if(path[v] != -1){
            cout << v << " " << path[v] << endl;
        }
        for(int j = 0; j < n; ++j){
            if(a[v][j] < min_e[j]){
                min_e[j] = a[v][j];
                path[j] = v;
            }
        }
    }

    return 0;
}