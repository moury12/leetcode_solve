#include <iostream>
#include <vector>
using namespace std;
  int removeDuplicates(vector<int>& nums) {
   
    int l=1;
        for(int i=1 ;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
            nums[l]=nums[i];
              l++;
            }
          
        }
        for (int v : nums){
    cout <<"  "<< v;
}
cout<<endl;
       return l;
    }
int main(){
    vector<int> vec={0,1,2,2,3,0,4,2};
int result = removeDuplicates(vec);
cout<< "result is : "<<result<<endl;


}
