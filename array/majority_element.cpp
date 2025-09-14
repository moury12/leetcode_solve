#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElementBruteForceApproach(vector<int> &nums)
{
    // time complexity O(n^2)
    for (int val : nums)
    {
        int freq;
        for (int el : nums)
        {
            if (val == el)
            {
                freq++;
            }
        }
        if (freq > nums.size() / 2)
        {
            return val;
        }
    }
    return -1;
}
int majorityElementOptimizedApproach(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end()); /// time complexity O(nlogn) for sort
    int freq;
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }
        if (freq > n / 2)
        {
            return ans;
        }
    }
}
int majorityElementMooresVotingAlgo(vector<int> &nums)
{
    /// time complexity O(n)
    int n = nums.size();
    int freq = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}
int main()
{
    vector<int> input = {2, 2, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int res = majorityElementMooresVotingAlgo(input);
    cout << res << endl;
}