#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    /// jehetu amra mid er age pise check kortesi aijnno first and last index st end dhora jabe na
/// r eta always mountain shape er hobe aijnno first r last index kokhno peak index hobe na 
    int st =1;
    int end = arr.size()-2;
   
    while (st<=end){
         int mid  = (st+end)/2;
///case 1 : mid jodi peak point hoy
        if(arr[mid-1]< arr[mid]&& arr[mid]> arr[mid+1] ){
            return mid;
        }
        /// case 2 : mid jodi peak point er age thake
        else if(arr[mid]< arr[mid+1]){
            st = mid +1;
        }
/// case 3 : mid jodi peak point er pore thake

        else {
            end = mid -1 ;
        }
    }
        return -1;
    }
int main(){
      vector<int> nums = {0,10,5,2};
    cout << peakIndexInMountainArray(nums);
}