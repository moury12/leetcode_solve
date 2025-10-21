#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int findClosestNumber(vector<int> &nums)
{
int n = nums.size();
int minDistance = INT_MAX;
int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int res = abs(nums[i] - 0);
        minDistance = min(res, minDistance);
       if(minDistance>=res){
        ans = max(nums[i],ans);
       }
    }
    return ans;
}
int main()
{
    vector<int> nums = {2,-1,1};
    cout << findClosestNumber(nums);
}