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

    string s;
    cin >> s;

    vector<int> pi = f(s);

    for(int i = 0; i < pi.size(); ++i){
        cout << pi[i] << " ";
    }

    return 0;
}