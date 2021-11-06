#include <iostream>
#include <vector>

using namespace std;

//n^3
vector<int> f(string s){
   int n = s.size();
   vector<int> pi(n);
   for(int i = 0; i < n; ++i){
       for(int k = 0; k <=i; ++k){
           if(s.substr(0,k) == s.substr(i - k + 1, k)){
               pi[i] = k;
           }
       }
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