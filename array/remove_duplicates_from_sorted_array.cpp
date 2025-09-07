#include <iostream>
#include <vector>
using namespace std;
  int removeDuplicates(vector<int>& nums) {
    int r=1;
    int l=0;
        for(int i=0 ;i<nums.size();i++){
            if(nums[l]!=nums[r]){
            nums[l]=nums[i];
               r++; 
            }
         
        }
        for (int v : nums){
    cout <<"  "<< v;
}
cout<<endl;
       return k;
    }
int main(){
    vector<int> vec={0,1,2,2,3,0,4,2};
int result = removeDuplicates(vec);
cout<< "result is : "<<result<<endl;


}
