#include <iostream>
#include <vector>

using namespace std;
  int removeElement(vector<int>& nums, int val) {
int k=0;
        for(int i=0 ;i<nums.size();i++){
            if(nums[i]!=val){
            nums[k]=nums[i];
               k++; 
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
int result = removeElement(vec,2);
cout<< "result is : "<<result<<endl;


}
