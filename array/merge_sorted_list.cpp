#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/// Time complexity O(m+n)
/// space Complexity O(1)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx = m+n-1;
    int i = m-1;
    int j = n-1;
    while (i>=0 && j >=0)
    {
        if(nums1[i]< nums2[j]){
            nums1[idx] = nums2[j];
            idx--;
            j--;

        }else{
            nums1[idx]= nums1[i];
            idx--;
            i--;
        }
    }

        while (j>=0)
        {
            nums1[idx]= nums2[j];
            idx--;
            j--;
        }
        
    
  for(int v : nums1){
    cout << v << ",";
  }
}

int main()
{
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;
    merge(nums1, m, nums2, n);
}