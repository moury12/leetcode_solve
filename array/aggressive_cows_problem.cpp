#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isPossible(vector<int> nums, int n, int m, int mid)
{
  
    int lastPosition = nums[0];
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] - lastPosition) >= mid)
        {
            lastPosition = nums[i];
            c++;
        }
         if (c == m)
    {
        return true;
    }
    }
   
    return false;
}
int locateStall(vector<int> nums, int n, int m)
{
   sort(nums.begin(), nums.end());
    // for (int i = 0; i < n; i++)
    // {
    //     minDistance = min(minDistance, nums[i]);
    //     maximumDistance = max(maximumDistance, nums[i]);
    // }
    int st = 1;
    int end = nums[n-1] - nums[0];
    int ans = -1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        // cout << " mid :" << mid << endl;
        if (isPossible(nums, n, m, mid))
        {
            ans = mid;
            // cout << " ans :" << ans;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 8, 4, 9};
    int n = 5;
    int c = 3;
    cout << locateStall(nums, n, c);

    return 0;
}