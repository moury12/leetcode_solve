#include <iostream>
#include <vector>
using namespace std;
int findUniqueValue(vector<int> & vec){
        int val =0;
    for(int v : vec){
    val = v^val;
    }
    return val;
}
int main(){
    vector<int> vec={2,3,2};
  int result =  findUniqueValue(vec);
  cout<< "unique val: "<< result<< endl;
}