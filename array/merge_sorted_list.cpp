#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void mergeBruteForce(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < m; i++)
    {
        
            nums1[m + i] = nums2[i];
        
    }
sort(nums1.begin(), nums1.end());
    for(int v : nums1){
        cout << v<<" ,  ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    mergeBruteForce(nums1, m, nums2, n);
}