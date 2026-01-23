#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
// 4টা সংখ্যা খুঁজছে যাদের যোগফল = target
// duplicate বাদ দিয়ে
// efficient ভাবে
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
// Time: O(n³)
// Space: O(1) extra (answer বাদ)
    vector<vector<int>> ans;
    int n = nums.size();
// Without sorting → two pointer impossible
    sort(nums.begin(), nums.end());
// 4Sum = 2 loops + 2 pointers
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
