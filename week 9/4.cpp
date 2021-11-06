#include <iostream>
#include <vector>

using namespace std;

vector<int> f(string s){
   int n = s.size();
   vector<int> pi(n);
   for(int i = 1; i < n; ++i){
       int j = pi[i-1];
       while(j > 0 && s[i] != s[j]){
           j = pi[j - 1];
       }
       if(s[i] == s[j]) j = j + 1;
       pi[i] = j;
   }
   return pi;
}


int main(){

    string s, t;
    cin >> s;
    cin >> t;

    string n = s + "#" + t;

    vector<int> pi = f(n);

    for(int i = 0; i < pi.size(); ++i){
        if(pi[i] == s.size()){
            cout << "found!";
        }
    }

    return 0;
}