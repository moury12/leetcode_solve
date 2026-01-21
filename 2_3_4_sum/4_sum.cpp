#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSumOptimized(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    //Step 1: Sort করা
//     কেন দরকার?
// two pointer কাজ করে শুধু sorted array এ
// duplicate সহজে skip করা যায়
// sum বড় না ছোট বোঝা যায়
    sort(nums.begin(), nums.end());
// nums[i] → প্রথম সংখ্যা fix
// বাকি দুইটা আমরা খুঁজবো
    for (int i = 0; i < n; i++)
    {
        // 👉 একই সংখ্যাকে আবার প্রথম element বানাতে চাই না
// 👉 না হলে same triplet বারবার আসবে
        if (i > 0 && nums[i] == nums[i - 1])
        {
            //continue nicher logic run krbe na i++ kore dibe 
            continue;
        }
// b = i এর পর থেকে শুরু
// c = array এর শেষ
        int b = i + 1;
        int c = n - 1;
        //👉 যতক্ষণ দুই pointer একে অপরকে cross না করে
// 👉 ততক্ষণ check করবো
        while (b < c)

        /* code */

        {
            int sum = nums[i] + nums[b] + nums[c];
            if (sum == 0)
            {
                vector<int> triplet = {nums[i], nums[b], nums[c]};
                ans.push_back(triplet);
                // 👉 valid triplet পেলাম
// 👉 next possible pair খুঁজতে pointer সরালাম
                b++;
                c--;
                while (b < c && nums[b] == nums[b - 1])
                // 👉 একই b value থাকলে skip
// 👉 duplicate triplet আটকানোর জন্য
                {
                    b++;
                }
            }
            else if (sum < 0)
            // sum ছোট
// 👉 sorted array → বড় করতে হলে b ডানে যাবে
            {
                b++;
            }
            else
            {
                //sum বড়
// 👉 ছোট করতে হলে c বামে যাবে
                c--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
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
