#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
                 if (j>i+1 && nums[j] == nums[j - 1])
            {
             continue;
            }
        
            int b = j + 1;
            int c = n - 1;
            while (b < c)
            {
                int sum = nums[i] + nums[j] + nums[b] + nums[c];
                if (sum == target)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[b], nums[c]};
                    ans.push_back(triplet);
                    b++;
                    c--;
                    while (b < c && nums[b] == nums[b - 1])
                    {
                        b++;
                    }
                }
                else if (sum < target)
                {
                    b++;
                }
                else
                {
                    c--;
                }
            }
           
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-3, -1, 0, 2, 4, 5};
    vector<vector<int>> ans = fourSum(nums, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " , ";
        }
        cout << endl;
    }
    return 0;
}
