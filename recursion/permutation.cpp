#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void permuteRecursiveCall(vector<int>& nums, int idx,  vector<vector<int>>& allPermutation){
int n = nums.size();
if(idx ==n){
    allPermutation.push_back(nums);
    return;
}
for (int i =idx ; i<n; i++){
    swap(nums[idx], nums[i]);
    permuteRecursiveCall(nums,  idx+1, allPermutation);
    //backtrekking 
    swap(nums[idx], nums[i]);

}
}
  vector<vector<int>> permute(vector<int>& nums) {
      vector<int> ans ;
vector<vector<int>> allPermutation;
int idx =0;
permuteRecursiveCall(nums,  idx, allPermutation);
return allPermutation;
}
int main(){
    vector<int> nums ={1,2,3};
  vector<vector<int>> result =  permute(nums);
  for(int i =0; i<result.size(); i++){
    for(int j =0; j<result[i].size(); j++){
    cout<< result[i][j];
}
cout << endl;
}
    return 0;
}