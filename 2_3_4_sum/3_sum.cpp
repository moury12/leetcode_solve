#include <iostream>
#include <vector>
vector<vector<int>> threeSum(vector<int> &nums)
{
    
}
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}