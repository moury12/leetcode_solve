#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isPossible(vector<int> nums, int n, int m, int mid)
{
    sort(nums.begin(), nums.end());
    int lastPosition = nums[0];
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] - lastPosition) >= mid)
        {
            lastPosition = nums[i];
            c++;
        }
    }
    if (c == m)
    {
        return true;
    }
    return false;
}
int locateStall(vector<int> nums, int n, int m)
{
    int minDistance = INT_MAX;
    int maximumDistance = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minDistance = min(minDistance, nums[i]);
        maximumDistance = max(maximumDistance, nums[i]);
    }
    int st = 1;
    int end = maximumDistance - minDistance;
    int ans = st;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        // cout << " mid :" << mid << endl;
        if (isPossible(nums, n, m, mid))
        {
            ans = max(ans, mid);
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