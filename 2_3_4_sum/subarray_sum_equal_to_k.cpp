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
  vector<int> prefix(n,0);
  prefix[0]=nums[0];
  for (int i = 1; i < n; i++) {
   prefix[i]=prefix[i-1]+nums[i];
    }
  for(int j =0 ; j<n;j++){
    if(prefix[j]==k) count++;
    int val = prefix[j]-k;
    if(um.find(val)!=um.end()){
      count+= um[val];
    }
   um[prefix[j]]++;
  }

  return count;
}
int main() {
  vector<int> nums = {1, 2, 3};
  int k = 3;
  cout << subarraySum(nums, k) << endl;
  return 0;}