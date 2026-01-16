#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> um = {};

    for (int i = 0; i < n; i++)
    {
        int first = nums[i];
        int sec = target - first;
        //um.find(sec): এটি ম্যাপের শুরু থেকে খোঁজা শুরু করে। যদি সংখ্যাটি খুঁজে পায়, তবে সেটির লোকেশন (Iterator) রিটার্ন করে। আর যদি খুঁজে না পায়, তবে সে ম্যাপের সীমানা পার হয়ে um.end() এ গিয়ে পৌঁছায়।

// != um.end(): এর মানে হলো "শেষ সীমানা পর্যন্ত পৌঁছানোর আগেই কিছু একটা পাওয়া গেছে"।
        if (um.find(sec) != um.end())
        {
            ans.push_back(um[sec]);
            
            ans.push_back(i);
            break;
        }
        // cout<<"um.find(sec) "<<um[sec]<<endl;
        um[first] = i;
        first++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (auto k : result)
    {
        cout << k << endl;
    }
    return 0;
}
