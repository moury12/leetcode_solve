#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 // Brute Force Subarray Sum

// Outer loop → start index
// Inner loop → end index
// sum reset only when start changes
// sum += nums[j]
// if sum == k → count++

// Time: O(n²)
// Space: O(1)

int subarraySumBruteForce(vector<int> &nums, int k) {
  int count = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum == k) {
        count++;
      }
    }
  }

  return count;
}

int subarraySum(vector<int> &nums, int k) {
  int count = 0;
  int n = nums.size();
unordered_map<int,int> um ;
  vector<int> prefix;
  for (int i = 0; i < n; i++) {
    if(i ==0){
           prefix.push_back(nums[i]);
    }else{
   prefix.push_back(prefix[i-1]+nums[i]);
    }
    // int sum = k-prefix[i];
if(um.find(prefix[i])!= um.end()){
    count++;
}
    um[prefix[i]]=count;

  }

  return count;
}
int main() {
  vector<int> nums = {1, 2, 3};
  int k = 3;
  cout << subarraySum(nums, k) << endl;
  return 0;}