#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
  if(nums.size()==1){
    return nums[0];
}
 int st = 0;
  int end = nums.size() - 1;

  while (st <= end)
  {
    int mid = (st + end) / 2;
    if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
    {
      return nums[mid];
    }
    else if (nums[mid] == nums[mid - 1])
    {
      if (mid % 2 == 0)
      {
        end = mid - 1;
      }
      else
      {
        st = mid + 1;
      }
    }
    else
    {
      if (mid % 2 == 0)
      {
        st = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
  }
  return -1;
}
int main()
{
  vector<int> nums = {1,2,2,3,3};
  cout << singleNonDuplicate(nums);
}