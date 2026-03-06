#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> partition(string s) {
        
    }
int main(){
    string s ="aab";
     vector<vector<string>> partitions =  partition(s);
  for(auto p : partitions){
    for (auto i : p)
    {
       cout<< i<<" ";

    }
    cout << endl;
  }
    return 0;
}