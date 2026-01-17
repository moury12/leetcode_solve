#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findDuplicateUsingMap(vector<int> &nums)
{
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++)
    {
        if (um.find(nums[i]) != um.end())
        {
            return nums[i];
        }
        um[nums[i]]++;
    }
    return 0;
}
int findDuplicateUsingConstantSpace(vector<int> &nums)
{

    int slow = nums[0], fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << " duplicate : " << findDuplicateUsingMap(nums)<<endl;
    cout << " findDuplicateUsingConstantSpace : " << findDuplicateUsingConstantSpace(nums)<<endl;
}