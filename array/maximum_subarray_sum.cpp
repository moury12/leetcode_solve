#include <iostream>
#include <vector>
using namespace  std;

int maxSubArray(vector<int>& nums) {
        ///brute force way Time complexity O(n^2)
            int maxVal= INT_MIN;
     for(int st =0; st<nums.size();st++){
        int currentSum=0;
for(int end =st ; end<nums.size();end++){
   currentSum +=nums[end];
   maxVal = max(maxVal,currentSum);
    }}
return maxVal;}
int maxSubArrayKadensAlgo(vector<int>& nums) {
        ///time complexity O(n)
        ///space complexity O(1)
        // This is why Kadane’s Algorithm is so powerful — it solves the Maximum Subarray Problem in linear time using only a couple of variables.
        int maxVal= INT_MIN;   int currentSum=0;
        for(int st=0; st<nums.size();st++){

    
     
        currentSum+=nums[st];
        maxVal = max(maxVal,currentSum);
        if(currentSum<0){
            currentSum=0;
        }

    }
        return maxVal;
    }


int main(){
vector<int> arr ={1,2,3,4,5};
cout<< maxSubArrayKadensAlgo(arr) <<endl;
}
