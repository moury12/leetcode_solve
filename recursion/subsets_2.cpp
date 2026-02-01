#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Time complexity O(n* 2^n)
void printSubset(vector<int> &arr, vector<int> &ans,int i,vector<vector<int>> &allSubsetans)
{
    if (i == arr.size())
    {
      allSubsetans.push_back(ans);
        return;
    }
    // include
    ans.push_back(arr[i]);
    printSubset(arr, ans, i + 1,allSubsetans);
    ans.pop_back();
    while(i<arr.size()-1&& arr[i]==arr[i+1]){
        i++;
    }
    printSubset(arr, ans, i + 1,allSubsetans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    vector<vector<int>> allSubsetans;
    printSubset(nums, ans, 0,allSubsetans);
    return allSubsetans;
}
 
int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> finalAns = subsetsWithDup(arr);
for(int i =0; i<finalAns.size(); i++){
    for(int j =0; j<finalAns[i].size(); j++){
    cout<< finalAns[i][j];
}
cout << endl;
}
}