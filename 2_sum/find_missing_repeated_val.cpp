#include <iostream>
#include <vector>
// #include <unordered_map>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans ={};
        
    }
    int main(){
        // num range hobe n^2 prjnnto eikhne n=2 so 4
        vector<vector<int>> grid = {{1,3},{2,2}}
        vector<int> ans =findMissingAndRepeatedValues(grid);
        for(int i: ans){
            cout<< i<<endl;
        }
        return 0;
    }