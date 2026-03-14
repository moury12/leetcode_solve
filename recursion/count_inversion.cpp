#include <iostream>
#include <vector>
using namespace std;
// time complexity O(nlogn)
// space complexity O(n)
void mergeing(vector<int> &arr, int l, int r, int mid, long& count)
{
    vector<int> temp;
    int left = l;
    int right = mid + 1;
    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            /// assume left part 0 - 2 prjnnto 2-0 +1 = 3 
            // 3 tai boro hbe so 
            count+=(mid -left +1 );
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}
void mergeSort(vector<int> &arr, int l, int r, long& count)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid + 1, r, count);
    mergeing(arr, l, r, mid, count);
}
long countInversions(vector<int> arr)
{
    long count = 0;
    mergeSort(arr, 0, arr.size() - 1, count);
    return count;
}
int main()
{
    vector<int> arr = {5,3,2,4,1};
    long count = countInversions(arr);

    cout << count << " ";

    return 0;
}