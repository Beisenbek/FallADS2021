#include <iostream>
#include <vector>

#define MAXN 100

using namespace std;

vector<int> ans;
bool used[MAXN];
int n;
int a[MAXN][MAXN];

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < n; ++i){
        if(a[v][i] == 1 && !used[i]){
            dfs(i);
        }
    }
    ans.push_back(v + 1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        if(!used[i]){
            dfs(i);
        }
    }


    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }

    cout << endl;
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }


    return 0;
}