#include <iostream>
#include <vector>
using namespace std;
  int removeDuplicates(vector<int>& nums) {
     if (nums.empty()) return 0; 
    int l=1;
    // cout << "nums.size() = " << nums.size() << endl;

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
vector<int> vec = {0,0,1,1,1,2,2,3,3,4}; 
int result = removeDuplicates(vec);
cout<< "result is : "<<result<<endl;


}
