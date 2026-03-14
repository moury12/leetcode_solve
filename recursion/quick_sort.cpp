#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr,int st , int end){
    int idx =st-1;/// list -1 index e pointer set kori prvious val paoar jonno
    int pivot= arr[end];/// last index r value ta pivot dhore nisi
    for(int j =st ; j<end ;j++){
        /// suru theke sesh prjnnto protibar loop chalaia digit gula check korar jonnno
        //pivot r theke choto konta 
        // choto gula left e shift korbo 
        //boro gula right 
        if(arr[j]<=pivot){
            //jokhn choto value pabe idx barabo initialy 0 te ashbe 
            // j index r value k idx index value dara swap korbe
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    // last e jokhn prottekta element traverse kora hoise
    //last j smaller digit paiselo oita j idx e rakhse tar porer idx pivot k swap krbo 
    /// tahole pviot r sorting location paoa jabe 
    swap(arr[idx+1], arr[end]);
    return idx+1;

}
void quickSortHelper(vector<int>& arr,int st , int end){
    if(st<end){
int pviotIdx = partition(arr, st, end);
quickSortHelper(arr, st , pviotIdx-1);
quickSortHelper(arr, pviotIdx+1, end);
    }

}
vector<int> quickSort(vector<int>& arr) {
quickSortHelper(arr, 0, arr.size()-1);
return arr;
}
int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};
    quickSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}