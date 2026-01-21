#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSumBruteForce(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    if (s.find(triplet) == s.end())
                    {
                        s.insert(triplet);
                        ans.push_back(triplet);
                        /* code */
                    }

                    // ans.push_back(triplet);
                }
            }
        }
    }
    return ans;
}
// time complexity O(N^2)
vector<vector<int>> threeSumOptimized(vector<int> &nums)
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
        int b = i + 1;
        int c = n - 1;
        while (b < c)

        /* code */

        {
            int sum = nums[i] + nums[b] + nums[c];
            if (sum == 0)
            {
                vector<int> triplet = {nums[i], nums[b], nums[c]};
                ans.push_back(triplet);
                b++;
                c--;
                while (b < c && nums[b] == nums[b - 1])
                {
                    b++;
                }
            }
            else if (sum < 0)
            {
                b++;
            }
            else
            {
                c--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSumOptimized(nums);
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
