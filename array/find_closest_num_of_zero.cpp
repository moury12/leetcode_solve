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
        int res = abs(nums[i]);
        if (res < minDistance)
        {
            minDistance = res;
            ans = nums[i];
        }
        else if (res == minDistance)
        {
            ans = max(nums[i], ans);
        }
        // minDistance = min(res, minDistance);

        //    if(minDistance>=res){
        //     ans = max(nums[i],ans);
        //    }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-4, -2, 1, 4, 8};
    cout << findClosestNumber(nums);
}