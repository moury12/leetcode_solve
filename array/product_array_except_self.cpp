#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> productExceptSelfBruteForce(vector<int> &nums)
{
    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        result.push_back(product);
    }
    for (int val : result)
    {
        cout << val << " ";
    }
    return result;
}
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    
   vector<int> result (n, 1);
    // vector<int> prefix(n, 1);
    // vector<int> suffix(n, 1);
int prefix=1;
int suffix=1;
    for (int i = 1; i < n; i++)
    {
        prefix  *= nums[i - 1];
        // suffix = suffix*nums[n-1];
        result[i]=prefix;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix =suffix * nums[i + 1];
        result[i] *= suffix ;
    }

    // for (int i = 0; i < n; i++)

    // {
    //     result.push_back(prefix[i] * suffix[i]);
    // }
     for (int i =0 ; i < n; i++)
    {
        nums[i]= result[i];
    }
    return nums;
}
int main()
{

    vector<int> nums = {1, 2, 3, 4};
    productExceptSelf(nums);
}