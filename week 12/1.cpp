#include <iostream>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;


int main(){
    int n;
    cin >> n;

    int d[n];
    vector<vector<pair<int, int > > > g(n);

    int inf = INT_MAX/2;

    int x;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> x;
            if(x != 0){
               g[i].push_back(make_pair(x, j));
            }
        }
    }

    /*
    for(int i = 0; i < n; ++i){
        cout << i << ": ";
        for(int j = 0; j < g[i].size(); ++j){
            cout << "{" << g[i][j].second << " " << g[i][j].first << "} ";
        }
        cout << endl;
    }*/

    int s;
    cin >> s;
    s--;

    for(int i = 0; i < n; ++i){
        d[i] = inf;
    }

    d[s] = 0;
    set<pair<int, int> > q; 
    q.insert(make_pair(d[s], s));


    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        for(int i = 0; i < g[v].size(); ++i){
            int to = g[v][i].second;
            int len = g[v][i].first;
            if(d[v] + len < d[to]){
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
            }
        }

    }

    for(int i = 0; i < n; ++i){
        cout << d[i] << " ";
    }


    return 0;
}