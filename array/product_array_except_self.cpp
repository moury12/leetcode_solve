#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> productExceptSelfBruteForce(vector<int>& nums) {
    vector<int> result={};
        for( int i = 0; i<nums.size(); i++){
            int product=1;
            for (int j = 0; j < nums.size(); j++)
            {
               if(i!=j){
                product*=nums[j];
                
               }
            }
            result.push_back(product);
            
        }
        for(int val : result){
cout << val <<" ";
        }
        return result;
    }
int main(){

    vector<int> nums ={1,2,3,4};
    productExceptSelfBruteForce(nums);
}